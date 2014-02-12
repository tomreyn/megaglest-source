// ==============================================================
//	This file is part of Glest (www.glest.org)
//
//	Copyright (C) 2014 Mark Vejvoda
//
//	You can redistribute this code and/or modify it under
//	the terms of the GNU General Public License as published
//	by the Free Software Foundation; either version 3 of the
//	License, or (at your option) any later version
// ==============================================================

#ifndef MEGAGLEST_CEGUI_MANAGER_H_
#define MEGAGLEST_CEGUI_MANAGER_H_

#include <string>
#include <map>
#include <vector>

using namespace std;

namespace CEGUI {
	class Window;
};

namespace Glest { namespace Game {

class MegaGlest_CEGUI_Events_Manager;

class MegaGlest_CEGUIManagerBackInterface {
public:
	MegaGlest_CEGUIManagerBackInterface() {}
	virtual ~MegaGlest_CEGUIManagerBackInterface() {};

	virtual bool EventCallback(CEGUI::Window *ctl, std::string name) = 0;
};

class MegaGlest_CEGUIManager {

private:

	//void initializeMainMenuRoot();

protected:

	CEGUI::Window *messageBoxRoot;
	std::map<string, std::vector<MegaGlest_CEGUI_Events_Manager *> > eventManagerList;
	MegaGlest_CEGUIManager();

	void initializeResourceGroupDirectories();
	void initializeDefaultResourceGroups();
	void initializeTheme();

	string getThemeName();
	string getThemeCursorName();

public:

	static MegaGlest_CEGUIManager & getInstance();
	virtual ~MegaGlest_CEGUIManager();

	void setupCEGUI();

	CEGUI::Window * loadLayoutFromFile(string layoutFile);
	void setCurrentLayout(string layoutFile);
	void setControlText(string controlName, string text);
	void setControlEventCallback(string containerName, string controlName,
			string eventName, MegaGlest_CEGUIManagerBackInterface *cb);
	CEGUI::Window * getControl(string controlName);

	string getEventClicked();

	void subscribeEventClick(std::string containerName, CEGUI::Window *ctl, std::string name, MegaGlest_CEGUIManagerBackInterface *cb);
	void unsubscribeEvents(std::string containerName);

	void setFontDefaultFont(string fontName, string fontFileName, float fontPointSize);
	void setImageFileForControl(string imageName, string imageFileName, string controlName);

	void subscribeMessageBoxEventClicks(std::string containerName, MegaGlest_CEGUIManagerBackInterface *cb);
	void displayMessageBox(string title, string text, string buttonTextOk, string buttonTextCancel);
	void hideMessageBox();
	bool isControlMessageBoxOk(CEGUI::Window *ctl);
	bool isControlMessageBoxCancel(CEGUI::Window *ctl);
};

}} //end namespace

#endif
