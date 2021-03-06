/*
 * Copyright 2015 Your Name <your@email.address>
 * All rights reserved. Distributed under the terms of the MIT license.
 */

#include <GraphicsDefs.h>
 
#ifndef MESSAGECONSTANTS_H
#define MESSAGECONSTANTS_H

//Colors
const rgb_color lightTextColor 	= { 224,220,224 };
const rgb_color darkTextColor 	= { 40,44,40 	};
const rgb_color stockPlusColor	= { 1, 205,192	};
const rgb_color stockMinusColor	= { 242,90,34 	};



//Messages
const uint32 kUpdateCompanyMessage 				= 'Updc';
const uint32 kUpdateSymbolMessage 				= 'Upds';
const uint32 kUpdateQuoteMessage 				= 'Upqm';
const uint32 kUpdateQuoteBatchMessage 			= 'Uqbm';
const uint32 kUpdateFailed 						= 'UFMb';

const uint32 kAutoUpdateMessage 				= 'UAUm';
const uint32 kSaveSettingsMessage 				= 'PREm';

//GUID
const uint32 kHideSearchWindowMessaage 			= 'SWCm';
const uint32 kShowSearchWindowMessage 			= 'SSWm';
const uint32 kShowSettingsWindowMessage			= 'SsWm';
const uint32 kQuitSettingsWindowMessage			= 'QSWm';

const uint32 kSearchTextChangedMessage 			= 'STCm';
const uint32 kSymbolListSelectionChanged 		= 'SLSc';
const uint32 kRemoveSelectedListItem			= 'RSLm';
const uint32 kRenameSelectedListItem			= 'kRSL';
const uint32 kUseSmallQuoteSize					= 'USQs';
const uint32 kUseNormalQuoteSize				= 'UNQs';
const uint32 kUseLargeQuoteSize					= 'ULQs';
const uint32 kEmptyListMessage					= 'ELMs';

const uint32 kListInvocationMessage				= 'PMSc';
const uint32 kListSelectMessage					= 'PMLM';


const uint32 kTransparencyChangedMessage		= 'TCHm';
const uint32 kTransparenyModificationMessage 	= 'TcHm';
const uint32 kRefreshChangedMessage				= 'RCMm';
const uint32 kRefreshModificationMessage		= 'RMMc';

// portfolio and portfoliomanager
const uint32 kPortfolioManagerChangeMessage		= 'kNPC';
const uint32 kPortfolioQuitMessage				= 'kPQM';
const uint32 kPortfolioUpdatedSettingsMessage 	= 'kPUM';

// PortfolioManagerWindow
const uint32 kCreateNewPortfolioMessage			= 'CNPm';
const uint32 kRenamePortfolioMessage			= 'kRPm';
const uint32 kPortfolioManagerSaveMessage		= 'SAVe';
const uint32 kPortfolioButtonPressedMessage 	= 'PSBm';
const uint32 kPortfolioRemovedSymbolMessage		= 'PRMe';
const uint32 kPortfolioAddedSymbolMessage		= 'PAMe';

#endif // _H
