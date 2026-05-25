import javax.swing.*;
import java.awt.*;

public class GraphPanel extends JPanel {

    private final Graph graph;

    public GraphPanel() {

        graph = new Graph();

        setBackground(Color.WHITE);
    }

    public Graph getGraph() {
        return graph;
    }

    @Override
    protected void paintComponent(Graphics g) {

        super.paintComponent(g);

        Graphics2D g2 = (Graphics2D) g;

        // Rysowanie krawędzi
        for (Edge edge : graph.getEdges()) {

            Vertex v1 = graph.findVertex(edge.getU());
            Vertex v2 = graph.findVertex(edge.getV());

            if (v1 == null || v2 == null)
                continue;

            int x1 = (int) v1.getX() + 100;
            int y1 = (int) v1.getY() + 100;

            int x2 = (int) v2.getX() + 100;
            int y2 = (int) v2.getY() + 100;

            g2.setColor(Color.BLACK);
            g2.drawLine(x1, y1, x2, y2);
        }

        // Rysowanie wierzchołków
        for (Vertex vertex : graph.getVertices()) {

            int x = (int) vertex.getX() + 100;
            int y = (int) vertex.getY() + 100;

            g2.setColor(Color.CYAN);
            g2.fillOval(x - 10, y - 10, 20, 20);

            g2.setColor(Color.BLACK);
            g2.drawOval(x - 10, y - 10, 20, 20);

            g2.drawString(
                    String.valueOf(vertex.getId()),
                    x - 4,
                    y + 4
            );
        }
    }
}
