/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */


#include "CompanyListItem.h"
#include <ListView.h>
#include <stdio.h>

CompanyListItem::CompanyListItem(Company *company)
	:BListItem()
	,fCompany(company) {
	
	//fCompany->PrintToStream();
}

CompanyListItem::~CompanyListItem() {
	delete fCompany;
}	

void 
CompanyListItem::DrawItem(BView *view, BRect rect, bool complete) {
	
	BListView *parent = dynamic_cast<BListView *>(view);
	const int32 index = parent->IndexOf(this);
	BRect frame = parent->ItemFrame(index);
	
	if (index % 2 == 0) {
		parent->SetHighColor(255, 255, 255);
	} else {
		parent->SetHighColor(245, 245, 245);
	}
	parent->FillRect(frame);
	parent->SetHighColor(40,40,40);
	parent->SetDrawingMode(B_OP_OVER);
	
	BFont font(be_plain_font);
	font.SetSize(17);
	parent->SetFont(&font);
	//parent->GetFont(&font);
	
	font_height fh;
	font.GetHeight(&fh);
	const float fontHeight = fh.ascent + fh.descent + fh.leading;
	const float center = (frame.Height() - fh.ascent) / 2;
	parent->SetFont(&font);
	
	parent->MovePenTo( 12, frame.LeftBottom().y - center);	
	parent->DrawString( fCompany->name.String() ); 
	printf("%s\n", fCompany->name.String());
}



void
CompanyListItem::Update(BView *view, const BFont *font) {
	
	font_height fh;
	font->GetHeight(&fh);
	const float height = fh.ascent + fh.descent + fh.leading + 2;
	
	SetHeight(34);
}
