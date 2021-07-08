#define MAX_MESSAGE_LENGTH 8

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  while(Serial.available() > 0)
  {
    static char IncomingMessage[MAX_MESSAGE_LENGTH];  
    static int PositionInArray = 0;
  
    char ByteIn = Serial.read();
  
    
    if(ByteIn != '\n' && (PositionInArray < MAX_MESSAGE_LENGTH - 1))
    {
      IncomingMessage[PositionInArray] = ByteIn;
      PositionInArray++;
    }
    else
    {
      IncomingMessage[PositionInArray] = '\n';

      Serial.println(IncomingMessage);
      
      PositionInArray = 0;
      
    }
    
  }

}

/*
 * Bugs: Wont write out until buffer/array has recieved all 8 chars
 *       Always ends with unusual characters
 */
