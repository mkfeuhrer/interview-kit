# Docker 101: Containerization Fundamentals

Docker is an open-source platform that enables developers to package applications and their dependencies into standardized units called containers. These containers are lightweight, portable, and consistent across different environments.

## Why Docker?

- **Consistency**: "Works on my machine" becomes "Works everywhere." Docker ensures that your application behaves the same way regardless of the underlying infrastructure.
- **Portability**: Containers can run on any system with Docker installed, whether it's your local machine, a virtual machine, or a cloud environment.
- **Isolation**: Each container runs in isolation, preventing conflicts between applications and their dependencies.
- **Efficiency**: Containers share the host OS kernel, making them much lighter and faster to start than traditional virtual machines.
- **Faster Development and Deployment**: Docker streamlines the development workflow, enabling quicker builds, testing, and deployment.

## Docker Architecture

![Docker Architecture](https://docs.docker.com/assets/images/architecture.svg)

## Docker Components

- **Docker Engine**: The core of Docker, it's a client-server application consisting of:
  - **Docker Daemon (dockerd)**: A persistent background process that manages Docker objects (images, containers, volumes, networks).
  - **Docker CLI (Command Line Interface)**: The primary way users interact with the Docker daemon.
  - **REST API**: Used by the CLI and other tools to communicate with the daemon.
- **Docker Images**: Read-only templates that contain the application code, libraries, dependencies, and any configuration files required to run an application. Images are built from a Dockerfile.
- **Docker Containers**: Runnable instances of Docker images. When you run an image, it becomes a container. Containers are isolated environments where your application executes.
- **Dockerfile**: A text file that contains a series of instructions for building a Docker image. Each instruction creates a layer in the image.
- **Docker Registry**: A centralized repository for storing and distributing Docker images. The most popular public registry is Docker Hub. You can also have private registries.
- **Docker Compose**: A tool for defining and running multi-container Docker applications. It uses a YAML file to configure application services, networks, and volumes, allowing you to spin up an entire application stack with a single command.
- **Docker Volumes**: The preferred mechanism for persisting data generated by Docker containers. Volumes are managed by Docker and are independent of the container's lifecycle.
- **Docker Networks**: Enable communication between Docker containers and with the outside world. Docker provides various networking drivers (bridge, host, overlay, etc.).

## Common Docker Commands

```bash
# Docker system information
docker --version            # Displays the Docker version
docker info                 # Shows detailed information about the Docker environment

# Working with images
docker build -t <image-name>:<tag> .   # Builds a Docker image from a Dockerfile
docker images               # Lists all local Docker images
docker pull <image-name>:<tag>         # Pulls an image from a registry
docker push <image-name>:<tag>         # Pushes an image to a registry
docker rmi <image-name-or-id>          # Removes a Docker image

# Working with containers
docker run -d -p <host-port>:<container-port> --name <container-name> <image-name>:<tag>  # Runs a container
docker ps                   # Lists all running containers
docker ps -a                # Lists all containers (running and stopped)
docker stop <container-name-or-id>     # Stops a running container
docker start <container-name-or-id>    # Starts a stopped container
docker restart <container-name-or-id>  # Restarts a container
docker rm <container-name-or-id>       # Removes a stopped container (-f to force)
docker exec -it <container-name-or-id> /bin/bash  # Opens a shell in a container
docker logs <container-name-or-id>     # Displays the logs of a container

# Working with volumes and networks
docker volume ls            # Lists Docker volumes
docker network ls           # Lists Docker networks

# Docker Compose
docker-compose up -d        # Starts all services defined in docker-compose.yml
docker-compose down         # Stops and removes all services defined in docker-compose.yml
```

## Docker Use Cases

- **Microservices Architecture**: Packaging each microservice into its own container.
- **CI/CD Pipelines**: Providing consistent build and test environments.
- **Development Environments**: Ensuring developers work with identical setups.
- **Application Isolation**: Running multiple applications on the same host without conflicts.
- **Hybrid Cloud Deployments**: Deploying applications consistently across on-premises and cloud environments.

## Docker Best Practices

### Building Efficient Images

- **Use specific base images**: Use specific versions of base images (`node:18` instead of `node:latest`).
- **Multi-stage builds**: Reduce final image size by using multi-stage builds to include only what's needed for production.
- **Layer caching**: Order Dockerfile instructions from least to most frequently changing.
- **Minimize layer count**: Combine related commands using `&&` and `\` to reduce layers.
- **.dockerignore**: Use a `.dockerignore` file to exclude unnecessary files from the build context.

### Example of Multi-stage Build (Go application)

```dockerfile
# Build stage
FROM golang:1.19-alpine AS builder
WORKDIR /app
COPY go.mod go.sum ./
RUN go mod download
COPY . .
RUN CGO_ENABLED=0 GOOS=linux go build -o /app/myapp

# Final stage
FROM alpine:3.17
WORKDIR /app
COPY --from=builder /app/myapp .
EXPOSE 8080
CMD ["./myapp"]
```

### Security

- **Run containers as non-root**: Add a user and group in your Dockerfile and use the `USER` directive.
- **Scan images**: Use tools like Docker Scout, Trivy, or Snyk to scan for vulnerabilities.
- **Use secrets management**: For sensitive data, use Docker secrets or mount from secure storage.
- **Read-only filesystems**: Use `--read-only` flag when appropriate.

### Container Management

- **Health checks**: Add HEALTHCHECK instructions to Dockerfiles or health check configurations in compose files.
- **Resource limits**: Set memory and CPU limits to prevent resource exhaustion.
- **Logging**: Configure proper logging drivers.
- **Container orchestration**: For production, consider using Kubernetes, Docker Swarm, or ECS.

## Docker Compose Example

```yaml
version: '3.8'

services:
  web:
    build: ./web
    ports:
      - "8080:80"
    depends_on:
      - api
    environment:
      - API_URL=http://api:3000
    networks:
      - frontend
      - backend

  api:
    build: ./api
    ports:
      - "3000:3000"
    depends_on:
      db:
        condition: service_healthy
    environment:
      - DB_HOST=db
      - DB_USER=postgres
      - DB_PASSWORD=password
      - DB_NAME=mydb
    networks:
      - backend

  db:
    image: postgres:14-alpine
    volumes:
      - db-data:/var/lib/postgresql/data
    environment:
      - POSTGRES_USER=postgres
      - POSTGRES_PASSWORD=password
      - POSTGRES_DB=mydb
    healthcheck:
      test: ["CMD-SHELL", "pg_isready -U postgres"]
      interval: 5s
      timeout: 5s
      retries: 5
    networks:
      - backend

networks:
  frontend:
  backend:

volumes:
  db-data:
```

## Troubleshooting Docker

### Common Issues and Solutions

| Issue | Solution |
|-------|----------|
| Container won't start | Check logs with `docker logs <container>` |
| Permission denied | Ensure proper file permissions or run as non-root user |
| Port already in use | Change host port mapping or stop service using the port |
| Out of disk space | Run `docker system prune` to clean unused resources |
| Image pull failures | Check registry authentication and network connectivity |

### Debugging Commands

```bash
# View container details
docker inspect <container>

# Check resource usage
docker stats

# View logs with timestamps
docker logs --timestamps <container>

# Continuous log streaming
docker logs -f <container>

# Execute commands in container for debugging
docker exec -it <container> /bin/sh

# Check networks
docker network inspect <network-name>
```

## Docker in Production

### Container Orchestration

- **Kubernetes**: Industry standard for container orchestration
- **Docker Swarm**: Native clustering for Docker
- **Amazon ECS/EKS**: AWS container services
- **Azure AKS**: Azure Kubernetes Service
- **Google GKE**: Google Kubernetes Engine

### Monitoring and Observability

- **Prometheus + Grafana**: Metrics collection and visualization
- **cAdvisor**: Container resource usage and performance
- **Elasticsearch + Fluentd + Kibana (EFK)**: Log aggregation and analysis
- **Datadog/New Relic**: Commercial observability platforms

### CI/CD with Docker

- Build images in CI pipeline
- Run tests in containers
- Tag images with build/commit information
- Push to registry on successful tests
- Deploy to staging/production environments

## Docker vs. Other Technologies

| Technology | Comparison |
|------------|------------|
| Virtual Machines | Docker shares the host kernel, VMs have complete OS; Docker is lighter and faster to start |
| Podman | Compatible with Docker, runs without daemon, better security model with rootless containers |
| containerd | Lower-level container runtime that Docker now uses internally |
| LXC/LXD | Linux containers with different focus; Docker originally built on LXC |
| Buildah | Alternative to Docker for building OCI images |

## Resources

- [Official Docker Documentation](https://docs.docker.com/)
- [Docker Hub](https://hub.docker.com/)
- [Play with Docker](https://labs.play-with-docker.com/)
- [Docker GitHub Repository](https://github.com/docker)
- [Docker Community Forums](https://forums.docker.com/)
