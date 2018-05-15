#ifndef CREW_H
#define CREW_H

#include "Material.h"
#include <vector>
#include <string>


class Crew
{
private:
	string producer;
	string director;
	string writer;
	vector<string> castOfActors;
	string editor;
	string productionDesigner;
	string setDecorator;
	string costumeDesigner;

public:
	/*Crew(string crewDetails);*/
	vector<string> getCrewDetails();

	void setProducer(string producerName);
	void setDirector(string directorName);
	void setWriter(string writerName);
	void addActors(string castOfActors);
	void setEditor(string editorName);
	void setProductionDesigner(string productionDesignerName);
	void setSetDecorator(string setDecoratorName);
	void setCostumerDesigner(string costumeDesignerName);

	string getProducer();
	string getDirector();
	string getWriter();
	vector<string> getActors();
	string getEditor();
	string getProductionDesigner();
	string getSetDecorator();
	string getCostumerDesigner();

};

#endif
