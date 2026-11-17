
# UDP Telemetry Ingest & Ring-Buffer Dispatcher

> Status: in progress

A multi-threaded C++ daemon that receives live binary telemetry over UDP, like a ground station receiving from a drone or rocket. It drops raw packets into a lock-free ring buffer and uses a worker thread pool to parse and dispatch them in real time, without blocking the socket.

## Architecture

```
UDP socket --> receive thread --> lock-free ring buffer --> worker pool --> sinks
```

## Roadmap

- [ ] UDP receive loop
- [ ] Lock-free ring buffer (`ring_buffer.hpp`)
- [ ] Worker pool with clean shutdown
- [ ] Packet parsing and dispatch
- [ ] Drop counter and basic metrics
- [ ] Stress tests under ThreadSanitizer
- [ ] Benchmarks (none measured yet)

## Decisions to make

- One shared queue (MPMC), or one SPSC ring per worker?
- What happens when the queue is full? Count the drop, never block the socket.
- Packet format: custom header, MAVLink, or CCSDS?
