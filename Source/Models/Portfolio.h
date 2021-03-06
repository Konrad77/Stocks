/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */
#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <SupportDefs.h>
#include <support/String.h>
#include "QuoteListItem.h"

class BList;
class BHandler;
class BMessenger;
class BMessage;
class SettingsManager;
class Portfolio {
public:
	Portfolio(BString name);
	~Portfolio();

	void SetTransparency(uint8 transparency);
	void SetRefreshRate(uint8 seconds);
	void SetQuoteType(QuoteType type);
	void SetTarget(BHandler *handler);
	void Add(const char *symbol);
	void Remove(const char *symbol);
	void HandlePortfolioUpdate(BMessage *message);

	void ReloadSavedData();
	
	uint8 Transparency() const;
	uint8 RefreshRate() const;
	
	QuoteType CurrentQuoteType() const;
		
	void SetName(BString name);
	
	BString Name();	
	BList *CurrentSymbols();
	
	status_t Save(BMessage &message);
	status_t Load(BMessage &message);
	
	bool IsEqual(const Portfolio &other) {
		return this->fName == other.fName;
	}
	
	void PrintToStream();	
private:

	int32 IndexOf(const char *symbol);
	bool HasSymbol(const char *symbol);
	
	void NotifyAdd(const char *symbol);
	void NotifyRemove(const char *symbol);
	
	void NotifyUpdates();
	
	BString 		fName;
	BList 			*fCurrentSymbols;
	BMessenger 		*fMessenger;
	SettingsManager *fSettingsManager;
	uint8 			fTransparency;
	uint8 			fRereshInterval;
	QuoteType 		fQuoteType;
};


#endif // _H
