# Numbers

## Orders of Magnitude

| Powers of 10    | Words       | Bytes    |
| --------------- | ----------- | -------- |
| 10<sup>3</sup>  | thousand    | kilobyte |
| 10<sup>6</sup>  | million     | megabyte |
| 10<sup>9</sup>  | billion     | gigabyte |
| 10<sup>12</sup> | trillion    | terabyte |
| 10<sup>15</sup> | quadrillion | petabyte |

## Powers of Two

| Powers of 2    | Decimal           | Bytes   | Words           |
| -------------- | ----------------- | ------- | --------------- |
| 2<sup>8</sup>  | 256               | 1 byte  | -               |
| 2<sup>16</sup> | 65,536            | 2 bytes | 65 thousand     |
| 2<sup>24</sup> | 16,777,216        | 3 bytes | 16 million      |
| 2<sup>32</sup> | 4,294,967,296     | 4 bytes | 4 billion       |
| 2<sup>40</sup> | 1,099,511,627,776 | 5 bytes | 1 trillion      |
| 2<sup>48</sup> | -                 | 6 bytes | 281 trillion    |
| 2<sup>56</sup> | -                 | 7 bytes | 72 quadillion   |
| 2<sup>64</sup> | -                 | 8 bytes | 9.2 quintillion |

## Sizes of Fundamental Types

### C++

| Type             | Size    |
| ---------------- | ------- |
| bool             | 1 byte  |
| char             | 1 byte  |
| short            | 2 bytes |
| float            | 4 bytes |
| int              | 4 bytes |
| long             | 4 bytes |
| pointer (32-bit) | 4 bytes |
| double           | 8 bytes |
| long long        | 8 bytes |
| pointer (64-bit) | 8 bytes |

### Java

| Type    | Size    |
| ------- | ------- |
| boolean | 1 byte  |
| char    | 2 bytes |
| short   | 2 bytes |
| float   | 4 bytes |
| int     | 4 bytes |
| double  | 8 bytes |
| long    | 8 bytes |

## Time

- 1 hour = 3,600 seconds
- 1 day = 86,400 seconds

## High Availability (HA)

| Availability %         | Downtime per Year |
| ---------------------- | ----------------- |
| 90% ("one nine")       | 36.5 days         |
| 99% ("two nines")      | 3.65 days         |
| 99.9% ("three nines")  | 9 hours           |
| 99.99% ("four nines")  | 50 minutes        |
| 99.999% ("five nines") | 5 minutes         |

## Latency numbers every programmer should know

### Latency Comparison Numbers

---

L1 cache reference 0.5 ns
Branch mispredict 5 ns
L2 cache reference 7 ns 14x L1 cache
Mutex lock/unlock 25 ns
Main memory reference 100 ns 20x L2 cache, 200x L1 cache
Compress 1K bytes with Zippy 10,000 ns 10 us
Send 1 KB bytes over 1 Gbps network 10,000 ns 10 us
Read 4 KB randomly from SSD* 150,000 ns 150 us ~1GB/sec SSD
Read 1 MB sequentially from memory 250,000 ns 250 us
Round trip within same datacenter 500,000 ns 500 us
Read 1 MB sequentially from SSD* 1,000,000 ns 1,000 us 1 ms ~1GB/sec SSD, 4X memory
HDD seek 10,000,000 ns 10,000 us 10 ms 20x datacenter roundtrip
Read 1 MB sequentially from 1 Gbps 10,000,000 ns 10,000 us 10 ms 40x memory, 10X SSD
Read 1 MB sequentially from HDD 30,000,000 ns 30,000 us 30 ms 120x memory, 30X SSD
Send packet CA->Netherlands->CA 150,000,000 ns 150,000 us 150 ms

### Notes

1 ns = 10^-9 seconds
1 us = 10^-6 seconds = 1,000 ns
1 ms = 10^-3 seconds = 1,000 us = 1,000,000 ns
