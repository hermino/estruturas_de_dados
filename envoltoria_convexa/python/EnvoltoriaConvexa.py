class Envoltoria:
	
	def __init__(self):
		self.pontos = []

	def armazena_pontos(self, x, y):
		self.pontos.append((x,y))

	def orientacao(self, p, q, r):
		self.val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])

		if self.val > 0:
			return 1
		elif self.val < 0:
			return 2
		else:
			return 0

	def forma_envoltoria(self, pontos, n):
		
		if n < 3:
			return 0

		self.env = []
		l = 0

		for i in range(0, n):
			if(self.pontos[i][0] < pontos[l][0]):
				l = i

		p = l

		while True:
			self.env.append(pontos[p])

			q = (p+2)%n

			for i in range(0, n):
				if self.orientacao(pontos[p], pontos[i], pontos[q])== 2:
					q = i

			p = q

			if(p == l):
				return 0

	def imprime(self):
		for i in range(0, len(self.env)):
			print(self.env[i])

	def build(self):
		self.forma_envoltoria(self.pontos, len(self.pontos))


a = Envoltoria()
a.armazena_pontos(3,2)
a.armazena_pontos(1,1)
a.armazena_pontos(2,4)
a.armazena_pontos(7,1)
a.armazena_pontos(5,3)
a.build()
a.imprime()
