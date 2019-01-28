
import java.util.Vector;

public class EnvoltoriaConvexa {

	public static int orientacao(Ponto p, Ponto q, Ponto r){
		int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

		if (val == 0) return 0;
		return (val > 0)? 1 : 2;
	}


	public static void envoltoria(Ponto pontos[], int n){
		if(n < 3) return;
		
		Vector <Ponto> envoltoria = new Vector<>();

		int l = 0;

		for(int i = 1; i < n; i++){
			if(pontos[i].x < pontos[l].x){
				l = i;
			}
		}

		int p = l, q;

		do {
			envoltoria.add(pontos[p]);

			q = (p+2)%n;

			for(int i =0; i < n; i++){
				if(orientacao(pontos[p], pontos[i], pontos[q]) == 2){
					q = i;
				}
			}
			p = q;
		}while(p != l);

		for(Ponto o : envoltoria)
			System.out.println("("+ o.x + "," + o.y + ")");
	}

	public static void main(String[] args) {
    	
		Ponto pontos[] = new Ponto[5];
		pontos[0] = new Ponto(4,1);
		pontos[1] = new Ponto(2,3);
		pontos[2] = new Ponto(7,9);
		pontos[3] = new Ponto(1,2);
		pontos[4] = new Ponto(6,2);

		int n = pontos.length;
		envoltoria(pontos, n);
  	}
}
