import java.io.BufferedReader;
import java.io.FileReader;

public class GraphParser {

    // Wczytywanie krawędzi
    public static void loadEdges(String filename, Graph graph) throws Exception {

        graph.clear();

        BufferedReader br = new BufferedReader(new FileReader(filename));

        String line;

        while ((line = br.readLine()) != null) {

            String[] parts = line.trim().split("\\s+");

            if (parts.length < 4)
                continue;

            String name = parts[0];

            int u = Integer.parseInt(parts[1]);
            int v = Integer.parseInt(parts[2]);

            double weight = Double.parseDouble(parts[3]);

            graph.addEdge(new Edge(name, u, v, weight));

            if (graph.findVertex(u) == null)
                graph.addVertex(new Vertex(u));

            if (graph.findVertex(v) == null)
                graph.addVertex(new Vertex(v));
        }

        br.close();
    }

    // Wczytywanie współrzędnych
    public static void loadCoordinates(String filename, Graph graph) throws Exception {

        BufferedReader br = new BufferedReader(new FileReader(filename));

        String line;

        while ((line = br.readLine()) != null) {

            String[] parts = line.trim().split("\\s+");

            if (parts.length < 3)
                continue;

            int id = Integer.parseInt(parts[0]);

            double x = Double.parseDouble(parts[1]);
            double y = Double.parseDouble(parts[2]);

            Vertex vertex = graph.findVertex(id);

            if (vertex != null) {

                // Skalowanie żeby było lepiej widać
                vertex.setX(x * 5);
                vertex.setY(y * 5);
            }
        }

        br.close();
    }
}
