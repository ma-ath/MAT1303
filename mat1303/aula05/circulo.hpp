class circulo {
		private:  // variaveis membro
		double _raio;
		double _centrox, _centroy;
	public:  // funcoes membro
		circulo(void);  // construtor
		circulo(double r, double cx, double cy);
		double area(void);
		double raio(void)
		{
			return _raio;
		}
};
