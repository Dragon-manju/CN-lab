// server code

import java.io.*;
import java.net.*;

public class UDPServer {
    public static void main(String[] args) {
        DatagramSocket socket = null;

        try {
            System.out.println("Server is started.");
            socket = new DatagramSocket(6788);
            byte[] buffer = new byte[1000];

            while (true) {
                DatagramPacket request = new DatagramPacket(buffer, buffer.length);
                socket.receive(request);

                String message = new String(request.getData(), 0, request.getLength());
                System.out.println("Message received from client: " + message);

                String responseMessage = message.toUpperCase() + " - From server to client";
                byte[] sendMsg = responseMessage.getBytes();

                DatagramPacket reply = new DatagramPacket(
                        sendMsg,
                        sendMsg.length,
                        request.getAddress(),
                        request.getPort()
                );
                socket.send(reply);
            }
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        }
    }
}


// client code

import java.io.*;
import java.net.*;

public class UDPClient {
    public static void main(String[] args) {
        DatagramSocket socket = null;

        try {
            socket = new DatagramSocket();
            String message = "Hello Server";
            byte[] messageBytes = message.getBytes();

            InetAddress host = InetAddress.getByName("127.0.0.1");
            int serverPort = 6788;

            DatagramPacket request = new DatagramPacket(
                    messageBytes,
                    messageBytes.length,
                    host,
                    serverPort
            );
            socket.send(request);

            byte[] buffer = new byte[1000];
            DatagramPacket reply = new DatagramPacket(buffer, buffer.length);
            socket.receive(reply);

            String replyMessage = new String(reply.getData(), 0, reply.getLength());
            System.out.println("Client received: " + replyMessage);
        } catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        } finally {
            if (socket != null && !socket.isClosed()) {
                socket.close();
            }
        }
    }
}
