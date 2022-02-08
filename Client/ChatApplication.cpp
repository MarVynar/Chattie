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
			
			}
			
			else {

			}
		}
		
		
		
		
		////////////
		
		ChatApplication::~ChatApplication(){
			
		
			delete mainMenu ;
			
		}
