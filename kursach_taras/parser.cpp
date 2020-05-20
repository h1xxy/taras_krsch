#include "parser.h"

using namespace std;



Parser::Parser()
{

}

Parser::~Parser()
{

}

void Parser::run(int *argcp, char **argv)
{
	ifstream file(argv[*argcp - 1]);
	
	string line;
	getline(file, line);	

	if (line == "#VRML V1.0 ascii")
	{
		while (getline(file, line))
		{			
			vector<string> result;
			result = getString(line, 1);
			if (result.back() == "Cube")
			{
				cube = shared_ptr<Cube>(new Cube());
				figureQueue.addFigure(cube);
				continue;
			}
			if (result.back() == "Prism")
			{
				prism = shared_ptr<Prism>(new Prism());
				figureQueue.addFigure(prism);
				continue;
			}
			if (result.back() == "Sphere")
			{
				sphere = shared_ptr<Sphere>(new Sphere());
				figureQueue.addFigure(sphere);
				continue;
			}
			if (result.back() == "Parallelepiped")
			{
				parallelepiped = shared_ptr<Parallelepiped>(new Parallelepiped());
				figureQueue.addFigure(parallelepiped);
				continue;
			}
			if (result.back() == "Cylinder")
			{
				cylinder = shared_ptr<Cylinder>(new Cylinder());
				figureQueue.addFigure(cylinder);
				continue;
			}
			if (result.back() == "Pyramid")
			{
				pyramid = shared_ptr<Pyramid>(new Pyramid());
				figureQueue.addFigure(pyramid);
				continue;
			}
			if (result.back() == "Cone")
			{
				cone = shared_ptr<Cone>(new Cone());
				figureQueue.addFigure(cone);
				continue;
			}
			if (result.back() == "height")
			{
				result = getString(line, 2);
				figureQueue.getLastFigure()->setHeight(stof(result.back()));
				continue;
			}
			if (result.back() == "width")
			{
				result = getString(line, 2);
				figureQueue.getLastFigure()->setWidth(stof(result.back()));
				continue;
			}
			if (result.back() == "depth")
			{
				result = getString(line, 2);
				figureQueue.getLastFigure()->setDepth(stof(result.back()));
				continue;
			}
			if (result.back() == "radius")
			{
				result = getString(line, 2);
				figureQueue.getLastFigure()->setRadius(stof(result.back()));
				continue;
			}
			if (result.back() == "length")
			{
				result = getString(line, 2);
				figureQueue.getLastFigure()->setLength(stof(result.back()));
				continue;
			}
			if (result.back() == "diffuseColor")
			{
				result = getString(line, 4);
				figureQueue.getLastFigure()->setColorR(stof(result.at(1)));
				figureQueue.getLastFigure()->setColorG(stof(result.at(2)));
				figureQueue.getLastFigure()->setColorB(stof(result.at(3)));
				continue;
			}
			if (result.back() == "translation")
			{
				result = getString(line, 4);
				figureQueue.getLastFigure()->setPositionX(stof(result.at(1)));
				figureQueue.getLastFigure()->setPositionY(stof(result.at(2)));
				figureQueue.getLastFigure()->setPositionZ(stof(result.at(3)));
				continue;
			}
		}
	}
	else
	{
		cout << "Error: Missing VRML header" << endl;
		_getch();
		return;
	}

	return;
}

vector<string> Parser::getString(string line, int num)
{
	int j = 0;
	vector<string> temp;
	for (int i = 0; i < num; i++)
	{
		while (line[j] == '\t' || line[j] == ' ')
			j++;
		temp.push_back("");
		while (line[j] && line[j] != '{' && line[j] != '\t' && line[j] != ' ' && line[j] != '\n')
			temp.back().push_back(line[j++]);
	}
	return temp;
}

