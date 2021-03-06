/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef QUOTEVIEW_H
#define QUOTEVIEW_H


#include <SupportDefs.h>
#include <Box.h>

class BStringView;
class BBox;
class BMessenger;
class BButton;
class Quote;
class QuoteView : public BBox {
public:
		QuoteView();
		~QuoteView();
		
			void SetQuote(Quote *quote, bool hasQuote);
			void SetTarget(BHandler *handler);
	virtual void AttachedToWindow();
	virtual void MessageReceived(BMessage *message);
							
private:
		void SetChange(float percent, float dollars);
		void SetupButton(bool hasQuote);
		void InitLayout();

		BView * MakeTitleGroup(const char *title, BStringView *right);
		const char * MakeText(const char * title, double value);
		
		BBox *MakeSeparator() const; 
	
	BMessenger 	*fMessenger;
	BButton 	*fPortfolioButton;
	BStringView *fTitle;
	BStringView *f52High;
	BStringView *f52Low;
	BStringView *fChangePercent;
	
	Quote *fQuote;
	bool fHasQuote;
};


#endif // _H
