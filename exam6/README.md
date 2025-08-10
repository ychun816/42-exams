# 🖥 Non-Blocking Multi-Client TCP Mini Server

How to build a **non-blocking, multi-client TCP server** in C using `bind()`, `listen()`, `select()`, `accept()`, and `recv()`.  
These five core functions work together to prepare the listening socket, wait for activity, accept incoming clients, and receive data without blocking.  

在非阻塞（Non-Blocking）、多客戶端 TCP 伺服器中，通常會用到 **五個核心函式**：  
`bind()`、`listen()`、`select()`、`accept()` 和 `recv()`。  
它們依序負責設定監聽 socket、等待事件、接受連線、接收資料，確保高效且不中斷地服務多個客戶端。

---

## 1. `bind()`

**Purpose:**  
Associates the server socket with a specific IP address and port number.

**Why needed:**  
Before a socket can receive incoming connections, it must be bound to the network address/port you want to serve.

**How to use:**
- Call `bind()` on the listening socket after creating it with `socket()`.
- Provide a `sockaddr_in` (IPv4) or similar structure specifying IP and port.

**中文補充說明：**  
將伺服器的 socket 綁定到特定的 IP 位址與埠號。  
在接收連線之前，必須先用 `bind()` 將 socket 與網路位址/埠號建立關聯。

---

## 2. `listen()`

**Purpose:**  
Marks the socket as a **listening socket** that can accept incoming connection requests.

**Why needed:**  
Turns the bound socket into a passive socket, ready to queue new connection requests until you call `accept()`.

**How to use:**
- Call `listen()` after `bind()`.
- Pass a backlog value indicating how many pending connections can be queued.

**中文補充說明：**  
將已綁定的 socket 設為「監聽模式」，以接收客戶端連線請求。  
`listen()` 會建立一個等待佇列（backlog），儲存尚未被 `accept()` 處理的連線。

---

## 3. `select()`

**Purpose:**  
Monitors multiple file descriptors (sockets) for readiness (read, write, or error).

**Why needed:**  
Allows the server to efficiently wait for activity on any socket without blocking on one.

**How to use:**
- Call `select()` in the main loop with the set of sockets to monitor.
- When it returns, check which sockets are ready for I/O.

**中文補充說明：**  
監控多個 sockets，檢查哪些已準備好進行讀取、寫入或發生錯誤。

---

## 4. `accept()`

**Purpose:**  
Accepts a new incoming connection on the listening socket and returns a new client socket descriptor.

**Why needed:**  
Required to establish communication with a new client.

**How to use:**
- When `select()` signals the listening socket is ready, call `accept()`.

**中文補充說明：**  
接受監聽 socket 上的新連線，返回客戶端 socket 描述符，與該客戶端開始通訊。

---

## 5. `recv()`

**Purpose:**  
Reads incoming data from a connected client socket.

**Why needed:**  
Used to receive messages from clients.

**How to use:**
- When `select()` signals a client socket is ready for reading, call `recv()`.

**中文補充說明：**  
從已連線的客戶端接收資料，通常用於讀取傳入訊息。

---

## 🔄 Typical Flow / 一般流程

```
socket()
   │
   ├─► bind()     // Bind to IP and port 綁定 IP 與埠號
   │
   ├─► listen()   // Start listening 開始監聽
   │
   └─► [Loop start]
        ├─► select()   // Wait for activity 等待事件
        ├─► if listening socket ready → accept()
        ├─► if client socket ready    → recv()
        └─► Repeat
```


---

## 📊 Summary

| Function    | Purpose (EN)                          | 中文功能說明                 | When to Call |
|-------------|---------------------------------------|------------------------------|--------------|
| `bind()`    | Associate socket with IP & port       | 將 socket 綁定到 IP 與埠號   | After `socket()` |
| `listen()`  | Enable listening mode, queue requests | 設為監聽模式，建立等待佇列   | After `bind()` |
| `select()`  | Wait for socket activity              | 等待 socket 活動             | Every loop iteration |
| `accept()`  | Accept new client connection          | 接受新客戶端連線             | When listening socket is ready |
| `recv()`    | Receive client data                   | 接收客戶端資料               | When client socket is ready |

---

## 📚 Notes

- **`bind()`** — Required to specify where the server will listen. Without it, your socket won’t be associated with any IP/port.  
  必須用來指定伺服器監聽的位址與埠號。

- **`listen()`** — Switches the socket into listening mode.  
  將 socket 設為監聽模式。

- **`select()`** — Allows checking multiple sockets at once.  
  可同時監控多個 socket 的狀態。

- **`accept()`** — Accepts a queued connection request.  
  接受等待佇列中的連線請求。

- **`recv()`** — Reads incoming data from a connected socket.  
  從已連線的 socket 讀取資料。

---

## TEST 
Compile Program with flag
```
gcc -Wall -Wextra -Werror -o mini_serv mini_serv.c
```
1. At terminal (1):
```./mini_serv 8081```

2. Open another two terminals (2),(3) (or even more), then send messages:
```nc 127.0.0.1 8081```


## 📜 License
This documentation is released under the MIT License.
