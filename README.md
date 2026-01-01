# 🚀 Real-Time Stock Simulator & Alert Engine (C++23)

A **real-time, low-latency stock alert system** built using **modern C++23**, designed to simulate **fintech / trading-style event processing** with safe concurrency, priority-based alerts, and lock-free data structures.

> 🧠 **Designed to showcase systems programming, multithreading, and design patterns used in FinTech & HFT systems.**

---

## ✨ One-Line Description

**Designed and implemented a real-time, low-latency stock alert engine in C++23 using multi-threading, Observer pattern, priority-based alerting, and lock-free data structures.**

---

## 📌 Features

- ✅ Real-time stock price simulation (multiple stocks)
- ✅ Threshold-based alert generation
- ✅ Publisher–Subscriber (Observer) pattern
- ✅ Multi-threaded event processing
- ✅ Lock-free queue for high-priority alerts
- ✅ Priority-based alert handling
- ✅ Graceful thread cancellation using `std::jthread` + `stop_token`
- ✅ Fully cross-platform (Windows/Linux)
- ✅ Copy-paste runnable using **VS Code + g++**

---

## 🧠 Why C++?

| Requirement | Why C++ |
|-----------|--------|
| Low Latency | Zero-cost abstractions |
| Concurrency | Fine-grained thread control |
| Performance | Lock-free & atomic operations |
| FinTech Usage | Widely used in trading systems |
| Modern Safety | RAII, `std::jthread`, `stop_token` |

---

## 🧵 Multithreading Model

| Component | Thread Type |
|---------|-------------|
| Price Simulation | `std::jthread` |
| Alert Processing | `std::jthread` |
| Shutdown Control | `stop_token` |
| Alert Queue | Lock-Free (SPSC) |

---

## 🧩 Design Patterns Used

### 🔁 Observer Pattern
- `PricePublisher` notifies all subscribers
- Decouples data source from alert logic
- Easily extensible

### 📣 Publish–Subscribe
- Multiple subscribers receive price updates
- Each subscriber maintains independent alert logic

### 🔐 Lock-Free Programming
- High-priority alerts pushed without mutex locks
- Minimizes latency on critical path

---

## ⚙️ Build & Run (Windows / VS Code)

### 🔧 Prerequisites
- **g++ 13+**
- **C++23 support**
- **MSYS2 / MinGW** (recommended)

---

### 🛠 Compile

```bash
g++ -std=c++23 *.cpp -o StockAlert
```
---

### ▶ Run

```bash
./StockAlert
```
---

### 📈 Sample Output

```cpp
[ALERT] TCS crossed 3275.4 priority=3275
[ALERT] NTPC crossed 361.2 priority=361
[ALERT] BSE crossed 2670.8 priority=2670
Stopping simulation...

```

---

### 🧪 Concurrency Safety Guarantees

- ✔ No data races

- ✔ RAII-based thread lifecycle management

- ✔ Cooperative thread cancellation

- ✔ Minimal locking on hot paths

- ✔ Deterministic and clean shutdown

---

### 🚀 Future Improvements

- TCP client/server for distributed alerts

- Persistent alert storage (DB / logging)

- Metrics & latency benchmarking

- Multi-producer / multi-consumer queues

- Load testing & stress benchmarking
  
---
### 👨‍💻 Author
- Diptendu Nandi
- 💼 Software Engineer
- 🧠 Focus: C++, Concurrency, Low-Latency Systems

### ⭐ If you find this project useful, consider starring the repository!



