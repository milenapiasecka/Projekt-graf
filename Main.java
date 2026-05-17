import javax.swing.*;
import java.awt.*;
import java.io.File;

public class Main {

    public static void main(String[] args) {

        SwingUtilities.invokeLater(() -> {

            JFrame frame = new JFrame("Wizualizacja grafu planarnego");

            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(1000, 800);

            GraphPanel panel = new GraphPanel();

            JButton loadGraphButton = new JButton("Wczytaj graf");
            JButton loadCoordsButton = new JButton("Wczytaj wspolrzedne");

            JPanel topPanel = new JPanel();

            topPanel.add(loadGraphButton);
            topPanel.add(loadCoordsButton);

            // Wczytywanie grafu
            loadGraphButton.addActionListener(e -> {

                JFileChooser chooser = new JFileChooser();

                int result = chooser.showOpenDialog(frame);

                if (result == JFileChooser.APPROVE_OPTION) {

                    File file = chooser.getSelectedFile();

                    try {

                        GraphParser.loadEdges(
                                file.getAbsolutePath(),
                                panel.getGraph()
                        );

                        panel.repaint();

                    } catch (Exception ex) {

                        JOptionPane.showMessageDialog(
                                frame,
                                "Blad wczytywania grafu"
                        );
                    }
                }
            });

            // Wczytywanie współrzędnych
            loadCoordsButton.addActionListener(e -> {

                JFileChooser chooser = new JFileChooser();

                int result = chooser.showOpenDialog(frame);

                if (result == JFileChooser.APPROVE_OPTION) {

                    File file = chooser.getSelectedFile();

                    try {

                        GraphParser.loadCoordinates(
                                file.getAbsolutePath(),
                                panel.getGraph()
                        );

                        panel.repaint();

                    } catch (Exception ex) {

                        JOptionPane.showMessageDialog(
                                frame,
                                "Blad wczytywania wspolrzednych"
                        );
                    }
                }
            });

            frame.setLayout(new BorderLayout());

            frame.add(topPanel, BorderLayout.NORTH);
            frame.add(panel, BorderLayout.CENTER);

            frame.setVisible(true);
        });
    }
}