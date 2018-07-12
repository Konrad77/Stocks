/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "SearchView.h"
#include <TextControl.h>
#include <Button.h>
#include <Messenger.h>
#include <StringView.h>
#include "MessageConstants.h"
#include <LayoutBuilder.h>
#include <GridView.h>
#include <GridLayoutBuilder.h>
#include <GroupLayoutBuilder.h>

#include <string.h>
#include <String.h>

SearchView::SearchView(BRect rect)
	:BView(rect, "SearchView", B_FOLLOW_TOP | B_FOLLOW_LEFT_RIGHT, B_WILL_DRAW)
	,fSearchTextControl(NULL)
	,fHitsView(NULL)
	,fMessenger(NULL) {
		
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
}

SearchView::~SearchView() {
	delete fMessenger;
}

void
SearchView::AttachedToWindow() {
	InitLayout();
}

void
SearchView::MessageReceived(BMessage *message) {
	
	switch (message->what) {
		case kSearchTextChangedMessage: {
			const char *text = TextControl()->Text();		
			BMessage msg(kSearchTextChangedMessage);
			msg.AddString("searchText", text);
			fMessenger->SendMessage(&msg);
		}
		break;
		default:
			break;
	}
}

void SearchView::SetNumberOfHits(int32 hits) {
	if (fHitsView == NULL) 
		return;
	
	BString str;
	str << "Stock symbols found: " << hits;	
	fHitsView->SetText(str.String());
}

void
SearchView::SetTarget(BHandler *handler) {
	delete fMessenger;
	fMessenger = new BMessenger(handler);
}

BTextControl *
SearchView::TextControl() {
	if (fSearchTextControl == NULL) {
		fSearchTextControl = new BTextControl("Filter", "Filter", "Name or Symbol", NULL);
		fSearchTextControl->SetModificationMessage(new BMessage(kSearchTextChangedMessage));
		fSearchTextControl->SetTarget(this);
	}
	return fSearchTextControl;
}

void
SearchView::InitLayout() {
	
	BGroupLayout *group = new BGroupLayout(B_VERTICAL);
	SetLayout(group);
	
	fHitsView = new BStringView("HitsView", "");
	fHitsView->SetAlignment(B_ALIGN_RIGHT);
	
	BGridLayout *grid = BGridLayoutBuilder(25.0)
		.Add(TextControl(), 0, 0)
		.Add(fHitsView, 1, 0);
		
	grid->SetMaxColumnWidth(0, 150);
	
	BGroupView *groupView = new BGroupView(B_VERTICAL, 0.0);
	
	BView *view = BGroupLayoutBuilder(B_VERTICAL, 5)
		.Add(grid->View())
		.SetInsets(10,10,10,10)
		.TopView();
	
	groupView->AddChild(view);
	AddChild(groupView);
}

