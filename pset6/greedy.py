def main():
    while True:
        change = float(input("O hai! How much change is owed?: "))
        if change >= 0:
            break

    change_cents = int(round(change * 100))
    coin_count = 0
    while change_cents > 0:
        if (change_cents - 25) >= 0: 
         
            change_cents = change_cents - 25 
            coin_count +=1
        
        elif (change_cents - 10) >= 0:
         
            change_cents = change_cents - 10
            coin_count +=1
        
        elif (change_cents - 5) >= 0:
         
            change_cents = change_cents - 5
            coin_count +=1
        
        elif (change_cents - 1) >= 0:
         
            change_cents = change_cents - 1 
            coin_count +=1 
               
    print(coin_count) 
main()    
    
