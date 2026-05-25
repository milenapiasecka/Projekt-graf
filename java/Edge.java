public class Edge {
    private final String name;

    private final int u;
    private final int v;

    private final double weight;

    public Edge(String name, int u, int v, double weight) {

        this.name = name;
        this.u = u;
        this.v = v;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }

    public int getU() {
        return u;
    }

    public int getV() {
        return v;
    }

    public double getWeight() {
        return weight;
    }
}
