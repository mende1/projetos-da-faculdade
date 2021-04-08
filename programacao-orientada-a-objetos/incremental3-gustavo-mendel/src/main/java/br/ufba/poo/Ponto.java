package br.ufba.poo;

public class Ponto {

    private int x;
    private int y;


    public Ponto (int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public Ponto comDeslocamento (int dx, int dy) {
        dx += x;
        dy += y;

        return new Ponto(dx, dy);
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Ponto)) return false;

        Ponto ponto = (Ponto) o;

        if (x != ponto.x) return false;
        return y == ponto.y;
    }

    @Override
    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }
}
