#pragma once
#include "figure.h"
#include <vector>
#include <memory>



class FigureQueue
{
public:
	FigureQueue();
	~FigureQueue();

	static void addFigure(std::shared_ptr<Figure> figure);
	static std::vector<std::shared_ptr<Figure>>& getQueue();
	static std::shared_ptr<Figure> getLastFigure();

private:
	static std::vector<std::shared_ptr<Figure>> figureVector_;
};