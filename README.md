# Network-Mapper-in-C

## Objective

Develop a network mapper tool in C to identify and map network servers and their TCP services. The project will cover TCP connections, including blocking and non-blocking I/O, and will progressively incorporate advanced features such as multithreading and raw sockets.

### Skills Learned


- TCP Connections: Understanding blocking and non-blocking TCP connections.
- Network Mapping: Techniques for discovering network services and servers.
- Multithreading: Using threads to handle concurrent network tasks.
- Raw Sockets: Advanced socket programming for deeper network analysis.


### Tools Used


- C Programming Language: For implementing the network mapper.
- Sockets API: For managing network connections.
- Makefile: For building and compiling the project.

## Steps
1. **Clone the Repository**

   ```bash
   git clone https://github.com/yourusername/network_mapper.git
   cd network_mapper

2. **Compile the Project**
 
    ```bash
   make


3. **Run the Network Mapper**
```bash
   ./nm-naive <port> <start-ip> <end-ip>
   Example:
   ./nm-naive 80 192.168.1.1 192.168.1.5
