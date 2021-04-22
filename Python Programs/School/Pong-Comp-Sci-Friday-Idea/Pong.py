import pygame, sys
import time
import random
pygame.init()



def setup():
        global display
        display = pygame.display.set_mode((800, 600))
        pygame.display.set_caption("Pong")
        icon = pygame.image.load("ball.jpeg")
        pygame.display.set_icon(icon)

        image = pygame.image.load("splash.jpg")
        display.blit(image, [0, 0])
        pygame.display.update()

        time.sleep(2)


def setup2():
  while True:
    img = pygame.image.load("setup2.png")
    display.blit(img, [0, 0])
    clicked = button(330,370,140,100)
    pygame.display.update()
    if clicked == True:
      return True

def button(x,y,w,h):
  for i in pygame.event.get():
    mouse = pygame.mouse.get_pos()
    click=pygame.mouse.get_pressed()
    if x+w > mouse[0] > x and y+h > mouse[1] > y:
      if click[0]==1:
        return True

def direct():
    dirr = pygame.image.load("direction.jpg")
    display.blit(dirr, (0, 0))
    pygame.display.update()
    time.sleep(1)
    
def new(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2):
    dirr = pygame.image.load("game.jpg")
    display.blit(dirr, [0, 0])
 
    pygame.draw.circle(display, orange, (c1pos1,c1pos2), 10)
    rect1=pygame.draw.rect(display,pink,(p1pos1,p1pos2,5,150))
    rect2=pygame.draw.rect(display,pink,(p2pos1,p2pos2,5,150))
            
def ball(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2,difference1,difference2):
  dirr = pygame.image.load("game.jpg")
  display.blit(dirr, [0, 0])
  rect1=pygame.draw.rect(display,pink,(p1pos1,p1pos2,5,150))
  rect2=pygame.draw.rect(display,pink,(p2pos1,p2pos2,5,150))
  c1pos1=c1pos1+difference1
  c1pos2=c1pos2+difference2

  pygame.draw.circle(display, orange, (c1pos1,c1pos2), 10)
  return c1pos1,c1pos2

    
    
def hit(p1pos1,p1pos2,op1pos2,p2pos1,p2pos2,op2pos2,c1pos1,c1pos2,differece1,difference2,a,b):
  
  if p1pos1-15<=c1pos1<=p1pos1+15 and p1pos2-5<=c1pos2<=p1pos2+150 and a==0:
    
    
    return True,1,0
  elif p2pos1-15<=c1pos1<=p2pos1+15 and p2pos2-5<=c1pos2<=p2pos2+150 and b==0:
    
   

    return True,0,1
   
  else:
    return False

def show_score(p1score,p2score):
  font = pygame.font.SysFont("Times New Roman", 50)

  s1=font.render(str(p1score),20,white)
  s2=font.render(str(p2score),20,white)

  display.blit(s1, (150, 300))
  display.blit(s2, (550, 300)) 

  pygame.display.update()  
  time.sleep(2)

def update(difference1,difference2):
        if difference1>0:
              difference1+=1
        else:
              difference1-=1

        if difference2>0:
              difference2+=1
        else:
              difference2-=1

        return (difference1,difference2)
def game(p1score,p2score):
  
  
  dirr = pygame.image.load("game.jpg")
  display.blit(dirr, (0, 0))
  c1pos1=398
  c1pos2=300
  difference1=random.randint(0,1)
  if difference1==0 and abs(difference1)<=11:
    difference1=random.randint(-8,-5)
  else:
    difference1=random.randint(5,8)

  difference2=random.randint(0,1)
  if difference2==0 and abs(difference1)<=11:
    difference2=random.randint(-8,-5)
  else:
    difference2=random.randint(5,8)


  pygame.draw.circle(display, orange, (c1pos1,c1pos2), 10)
  p1pos1=10
  p1pos2=200
  op1pos2=200
  rect1=pygame.draw.rect(display,pink,(p1pos1,p1pos2,5,150))

  p2pos1=780
  p2pos2=200
  op2pos2=200
  rect2=pygame.draw.rect(display,pink,(p2pos1,p2pos2,5,150))
  pygame.display.update()
  time.sleep(2)
  a=0
  b=0
  while True:

          if c1pos2>=590:
                difference2=difference2*-1
          elif c1pos2<=0:
                difference2=difference2*-1
          coords=ball(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2,difference1,difference2)
          if c1pos1<0:
            
            p2score+=1
            show_score(p1score,p2score)

            game(p1score,p2score)
          elif c1pos1>800:
            p1score+=1

            show_score(p1score,p2score)

            game(p1score,p2score)

          c1pos1=coords[0]
          c1pos2=coords[1]

          pygame.display.update()
          
          var_all=hit(p1pos1,p1pos2,op1pos2,p2pos1,p2pos2,op2pos2,c1pos1,c1pos2,difference1,difference2,a,b)
          if var_all!=False:
            check=var_all[0]
            a=var_all[1]
            b=var_all[2]
          else:
            check=var_all

          if check==True:
            difference1=difference1*-1
            t=update(difference1,difference2)
            difference1=t[0]
            difference2=t[1]
          
          for event in pygame.event.get():
                  if event.type == pygame.QUIT:
                        pygame.quit()
                        quit()
          keys = pygame.key.get_pressed()
          if keys[pygame.K_UP] and p2pos2>18:
                op2pos2=p2pos2
                p2pos2-=19

                new(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2)


          if keys[pygame.K_DOWN] and p2pos2 <440:
                op2pos2=p2pos2
                p2pos2+=19
                new(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2)
  
                

          if keys[pygame.K_w] and p1pos2>18:
                op1pos2=p1pos2
                p1pos2-=19
                
                new(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2)
 

          if keys[pygame.K_s] and p1pos2<440:
                op1pos2=p1pos2      
                p1pos2+=19
                new(p1pos1,p1pos2,p2pos1,p2pos2,c1pos1,c1pos2)

                
          pygame.display.update()       
          if max(p1score,p2score)==10:
            if p1score==10:
                img=pygame.image.load("end1.jpg")
                display.blit(img, [0, 0])

            else:
                img=pygame.image.load("end2.jpg")
                display.blit(img, [0, 0])

            pygame.display.update()
            time.sleep(3)
            pygame.quit()

            
          pygame.display.update()
        
clock = pygame.time.Clock()

def main():
    global clock
    global white,blue,green,red,orange,pink
    white = (255, 255, 255)
    blue =(0, 0, 255)
    green = (0, 255,0)
    red = (255, 0, 0)
    orange = (255,165,0)
    pink=(255,192,203)
    setup()
    direct()
    while True:  # main game loop
        global dt
        
        dt=clock.tick(0)
        
        for event in pygame.event.get():
        
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()
            setup2()
            while True:
              p1score=0
              p2score=0

              game(p1score,p2score)


main()
