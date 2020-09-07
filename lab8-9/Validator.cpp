#include "Validator.h"

void Validator::validate(const Car & c)
{
	string msg;
	if (c.getNrInmatriculare() == "")
		msg.append("Nr inmatriculare invalid. ");
	if (c.getProducator() == "")
		msg.append("Producator invalid. ");
	if (c.getModel() == "")
		msg.append("Model invalid. ");
	if (c.getTip() == "")
		msg.append("Tip invalid. ");

	if (msg.size() > 0) {
		throw ValidateException(msg);
	}

}
