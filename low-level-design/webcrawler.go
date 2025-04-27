package main

import (
	"fmt"
	"net/http"
	"sync"
)

type WebCrawler struct {
	maxDepth    int
	parallelism int
	visitedUrls map[string]bool
	mutex       sync.Mutex
	wg          sync.WaitGroup
	urlQueue    chan CrawlTask
}

type CrawlTask struct {
	url   string
	depth int
}

func NewWebCrawler(maxDepth, parallelism int) *WebCrawler {
	return &WebCrawler{
		maxDepth:    maxDepth,
		parallelism: parallelism,
		visitedUrls: make(map[string]bool),
		urlQueue:    make(chan CrawlTask, 100),
	}
}

func (wc *WebCrawler) Crawl(task CrawlTask) {
	defer wc.wg.Done()

	if task.depth > wc.maxDepth {
		return
	}

	wc.mutex.Lock()
	if wc.visitedUrls[task.url] {
		wc.mutex.Unlock()
		return
	}
	wc.visitedUrls[task.url] = true
	wc.mutex.Unlock()

	resp, err := http.Get(task.url)
	if err != nil {
		fmt.Printf("Error crawling %s: %v\n", task.url, err)
		return
	}
	defer resp.Body.Close()

	if resp.StatusCode != http.StatusOK {
		fmt.Printf("Non-OK HTTP status for %s: %d\n", task.url, resp.StatusCode)
		return
	}

	// Process page content
	wc.ProcessPageContent(task.url)

	// Extract links from the page
	links := wc.ExtractLinksFromPage(resp)

	// Enqueue links for further crawling
	for _, link := range links {
		wc.wg.Add(1)
		wc.urlQueue <- CrawlTask{url: link, depth: task.depth + 1}
	}
}

func (wc *WebCrawler) ProcessPageContent(url string) {
	// Implement your logic to process the page content
	fmt.Printf("Processing page: %s\n", url)
}

func (wc *WebCrawler) ExtractLinksFromPage(resp *http.Response) []string {
	var links []string
	// Process and collect links
	return links
}

func (wc *WebCrawler) StartCrawling(seedUrl string) {
	// Launch worker pool
	for i := 0; i < wc.parallelism; i++ {
		go wc.worker()
	}

	// Enqueue the seed URL
	wc.wg.Add(1)
	wc.urlQueue <- CrawlTask{url: seedUrl, depth: 0}

	// Wait for all tasks to finish
	wc.wg.Wait()
	close(wc.urlQueue)
}

func (wc *WebCrawler) worker() {
	for task := range wc.urlQueue {
		wc.Crawl(task)
	}
}

func main() {
	maxDepth := 3    // Specify the maximum depth
	parallelism := 5 // Specify the number of parallel workers

	webCrawler := NewWebCrawler(maxDepth, parallelism)
	webCrawler.StartCrawling("https://example.com") // Start crawling from a seed URL
}
