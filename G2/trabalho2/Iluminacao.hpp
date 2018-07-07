#ifndef ILUMINACAO_HPP
#define ILUMINACAO_HPP

class Iluminacao
{
private:
	float _mat_especular[4];
	float _mat_back[4];
	float _light_position[4];
	float _light_position1[4];
	float _light_position2[4];
	float _mat_shiness;
public:
	Iluminacao();
	void light_on();
	void light_off();
};

#endif
