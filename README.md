# Minitalk

## Overview
Minitalk is a simple data exchange program utilizing UNIX signals for inter-process communication. The objective is to implement a client-server architecture where the client sends a string message to the server, and the server receives and prints it using only UNIX signals.

## Features
- Server process listens for messages and prints them upon reception.
- Client sends messages to the server using UNIX signals.
- Supports handling multiple messages consecutively without restarting the server.
- Uses only `SIGUSR1` and `SIGUSR2` for communication.
- Efficient message transmission without excessive delays.

## Bonus Features
- Server acknowledges each received message by sending a confirmation signal to the client.
- Support for Unicode character transmission.

## Requirements
- C programming language
- UNIX-based operating system
- Allowed functions:
  - `write`
  - `ft_printf` or equivalent custom implementation
  - `signal`, `sigemptyset`, `sigaddset`, `sigaction`
  - `kill`, `getpid`
  - `malloc`, `free`
  - `pause`, `sleep`, `usleep`
  - `exit`

## Installation
Clone the repository and compile the project using `Makefile`:
```sh
make
```
This will generate the `server` and `client` executables.

## Usage
### 1. Start the Server
```sh
./server
```
The server will display its **PID** (Process ID), which the client needs to send messages.

### 2. Send a Message from the Client
```sh
./client <server_pid> "Your message here"
```
Replace `<server_pid>` with the actual PID displayed by the server.

## Example
```sh
# Open one terminal and start the server
./server
Server PID: 12345

# Open another terminal and send a message
./client 12345 "Hello, World!"
```
Expected Output on the Server:
```sh
Received message: Hello, World!
```

## Cleanup
To remove compiled binaries:
```sh
make clean
```
To remove all compiled files, including executables:
```sh
make fclean
```

