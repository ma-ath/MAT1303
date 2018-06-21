class iluminacao {
	float mat_especular[4];
	float mat_back[4];
	float light_position[4];
	float light_position1[4];
	float light_position2[4];
	float mat_shiness;
public:
	iluminacao();
	void light_on();
	void light_off();
};