class vetor {
private:
	int _n;
	float *_v;
public:
	friend ostream& operator<<(ostream& out, vetor& u)
	{
		for (int i = 0; i < u._n; i++)
			out << u._v[i] << ',';

		return out;
	}
};
