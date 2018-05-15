#include "Crew.h"

//Crew::Crew(string crewDetails)
//{
//
//}

vector<string> Crew::getCrewDetails()
{
	vector<string> returnCrewDetails;

	returnCrewDetails.push_back(producer);
	returnCrewDetails.push_back(director);
	returnCrewDetails.push_back(writer);
	vector<string> castOfActors;
	returnCrewDetails.push_back(editor);
	returnCrewDetails.push_back(productionDesigner);
	returnCrewDetails.push_back(setDecorator);
	returnCrewDetails.push_back(costumeDesigner);

	return returnCrewDetails;
}

void Crew::setProducer(string producerName)
{
	producer = producerName;
}

void Crew::setDirector(string directorName)
{
	director = directorName;
}

void Crew::setWriter(string writerName)
{
	writer = writerName;
}

void Crew::addActors(string actor)
{
	this->castOfActors.push_back(actor);
}

void Crew::setEditor(string editorName)
{
	editor = editorName;
}

void Crew::setProductionDesigner(string productionDesignerName)
{
	productionDesigner = productionDesignerName;
}

void Crew::setSetDecorator(string setDecoratorName)
{
	setDecorator = setDecoratorName;
}

void Crew::setCostumerDesigner(string costumeDesignerName)
{
	costumeDesigner = costumeDesignerName;
}

string Crew::getProducer()
{
	return producer;
}

string Crew::getDirector()
{
	return director;
}

string Crew::getWriter()
{
	return writer;
}

vector<string> Crew::getActors()
{
	return castOfActors;
}

string Crew::getEditor()
{
	return editor;
}

string Crew::getProductionDesigner()
{
	return productionDesigner;
}

string Crew::getCostumerDesigner()
{
	return costumeDesigner;
}

string Crew::getSetDecorator()
{
	return setDecorator;
}
