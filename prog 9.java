#server code

import java.net.*;
import java.io.*;

public class TCPClient {
    public static void main(String args[]) throws Exception {
        // Connect to the server
        Socket sock = new Socket("127.0.0.1", 4000);
        System.out.println("Enter the filename:");

        // Read filename from user input
        BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
        String fname = keyRead.readLine();

        // Send the filename to the server
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        pwrite.println(fname);

        // Read the file contents from the server
        InputStream istream = sock.getInputStream();
        BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));
        String str;
        System.out.println("File contents received from the server:");
        while ((str = socketRead.readLine()) != null) {
            System.out.println(str);
        }

        // Close all streams and the socket
        pwrite.close();
        socketRead.close();
        keyRead.close();
        sock.close();
    }
}


#client code




  import java.net.*;
import java.io.*;

public class TCPClient {
    public static void main(String args[]) throws Exception {
        // Connect to the server
        Socket sock = new Socket("127.0.0.1", 4000);
        System.out.println("Enter the filename:");

        // Read filename from user input
        BufferedReader keyRead = new BufferedReader(new InputStreamReader(System.in));
        String fname = keyRead.readLine();

        // Send the filename to the server
        OutputStream ostream = sock.getOutputStream();
        PrintWriter pwrite = new PrintWriter(ostream, true);
        pwrite.println(fname);

        // Read the file contents from the server
        InputStream istream = sock.getInputStream();
        BufferedReader socketRead = new BufferedReader(new InputStreamReader(istream));
        String str;
        System.out.println("File contents received from the server:");
        while ((str = socketRead.readLine()) != null) {
            System.out.println(str);
        }

        // Close all streams and the socket
        pwrite.close();
        socketRead.close();
        keyRead.close();
        sock.close();
    }
}



















