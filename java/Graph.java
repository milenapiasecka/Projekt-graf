import java.util.ArrayList;
import java.util.List;

public class Graph {

    private final List<Vertex> vertices;
    private final List<Edge> edges;

    public Graph() {

        vertices = new ArrayList<>();
        edges = new ArrayList<>();
    }

    public void addVertex(Vertex v) {
        vertices.add(v);
    }

    public void addEdge(Edge e) {
        edges.add(e);
    }

    public List<Vertex> getVertices() {
        return vertices;
    }

    public List<Edge> getEdges() {
        return edges;
    }

    public Vertex findVertex(int id) {

        for (Vertex v : vertices) {

            if (v.getId() == id)
                return v;
        }

        return null;
    }

    public void clear() {

        vertices.clear();
        edges.clear();
    }
}
