#include "Export.h"


void Export::exportToCVS(const std::string & fName, const std::vector<Car>& cars)
{
	std::ofstream out(fName, std::ios::trunc);
	if (!out.is_open()) {
		throw CarException("Unable to open file:" + fName);
	}
	for (const auto& c : cars) {
		out << c.getNrInmatriculare() << ",";
		out << c.getProducator() << ",";
		out << c.getModel() << ",";
		out << c.getTip() << std::endl;
	}
	out.close();
}

 void Export::exportToHTML(const std::string & fName, const std::vector<Car>& cars)
{
	std::ofstream out(fName, std::ios::trunc);
	if (!out.is_open()) {
		throw CarException("Unable to open file:" + fName);
	}
	out << "<html><body>" << std::endl;
	out << "<table border=\"1\" style=\"width:100 % \">" << std::endl;
	for (const auto& c : cars) {
		out << "<tr>" << std::endl;
		out << "<td>" << c.getNrInmatriculare() << "</td>" << std::endl;
		out << "<td>" << c.getProducator() << "</td>" << std::endl;
		out << "<td>" << c.getModel() << "</td>" << std::endl;
		out << "<td>" << c.getTip() << "</td>" << std::endl;
		out << "</tr>" << std::endl;
	}
	out << "</table>" << std::endl;
	out << "</body></html>" << std::endl;
	out.close();
}
