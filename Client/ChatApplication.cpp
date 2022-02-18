#include "ChatApplication.h"

		ChatApplication::ChatApplication(){
							
			////
			requestManager = new RequestManager();
			mainMenu = new MainMenu(requestManager);
			
			/////
			run();	
			
			
					
		}
		
		void ChatApplication::run(){
			
			if (mainMenu->showMenu()) {
				delete mainMenu;
				mainMenu = nullptr;
				//runCore
				chatCore = new ChatCore(requestManager);
			
			}
			
			else {

			}
		}
		
		
		
		
		////////////
		
		ChatApplication::~ChatApplication(){
			
		
			delete mainMenu ;
			
		}
