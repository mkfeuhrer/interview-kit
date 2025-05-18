# System Design Outline

This is a recommended approach to solving system design problems. Not all of these topics will be relevant for a given problem.

- Functional Requirements / Clarifications / Assumptions
- Non-Functional Requirements
  - Consistency vs Availability
  - Latency
    - How fast does this system need to be?
    - User-perceived latency
  - Data processing latency
  - Security
    - Potential attacks? How should they be mitigated?
  - Privacy
    - PII, PCI, or other user data
  - Data Integrity
    - How to recover from data corruption or loss?
  - Read:Write Ratio
  - Who is going to use it?
  - How are they going to use it?
- Core Entities
- Not in Scope (if required)
- APIs (if required)
- System Design

  - Scalability
    - How does the system scale? Consider both data size and traffic increases.
    - What are the bottlenecks? How should they be addressed?
    - What are the edge cases? What could go wrong? Assuming they occur, how should they be addressed?
    - How will we stress test this system?
    - Load Balancing
  - Auto-scaling / Replication
  - Caching
    - Partitioning
  - Replication
  - Business Continuity and Disaster Recovery (BCDR)
  - Internationalization / Localization
    - How to scale to multiple countries and languages? Don't assume the US is English-only.

- APIs
  - Public and/or internal APIs?
  - Are the APIs simple and easy to understand?
  - How are entities identified?
- Storage Schemas
  - SQL vs NoSQL
  - Message Queues
