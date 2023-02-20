# AWBW-Map-Generator
Simple comptetitive-able map generator for Advance Wars By Web.  
Original code written by Ilese (a.k.a NQ BN). I just edit it from Scribd so that line breaks and comments are in their correct position.  
  
Uploaded onto Github for easier access (with permission of the original owner).


# The Ideas (by Ilese)
> Some take on coding a basic map generator (with if else):
> -You create the map by generating the .txt file, you just need to do half of the thing and mirror it.
> 
> -Variable that you need: Map size(X,Y), Base(factory), Cities(Including Airport, Tower and HQ)
> 
> -First we need to decide the map size with x, y (or weight/height)
> 
> -Then set up base location. To maximize the fight zone and use as much of the space as possible, fixed the base location on the edge of the map (like X1~2 or Y1~2 depend on which direction you set your mirror)
> 
> -No matter which side you mirror your map, player 1 two base side + player 2 one base/airport side; or player 1(2) all three base + airport, you should be able to fixed bases positions with each other to form a simple 2bv1b1a setting: Base1 chain with base2 four range radius (to make 2b side); Base1 chain with base3 fourteen tiles radius; Base 2 chain with base3 ten tiles radius (to set base 3 locations far away).
> 
> -Moving one to cities around bases, you can have 2 variables of cities, safe cities and contested cities.
> 
> -x number of safe cities in 4-5 radius around each base. (3-4 should do) 
> 
> -x number of contested cities in 7-8 radius around each base. (2-3 should do) 
> 
> -Chain cities with each other so they are at least 3-4 tiles away.
> 
> -Turn either a safe city or a contested city on lone base side  into an airport (HQ and tower preferred to be between safe and contested so maybe they’re best manually set) depend on how rushy the map play out.
> 
> -Rest of the map should be plain, then randomize them into mountain and forest, you can control the randomness ratio to your preferences.
> 
> -Run the program and mirror the .txt file.
> 
> -Spam same-y cookie cutter high C- low B rank map.
> 
> Like this one: https://awbw.amarriner.com/prevmaps.php?maps_id=83418
> 
