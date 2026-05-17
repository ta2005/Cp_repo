#!/bin/bash

echo "Creating directories..."
mkdir -p USACO CSES Codeforces/Contests Codeforces/Practice Unsorted

echo "Moving USACO files..."
# Arrays of known USACO filenames based on your list
usaco_files=(
    "angry_cow.cpp" "closing_the_farm.cpp" "closing.in" "closing.out" 
    "cowdance.cpp" "cowlib.cpp" "cow-libi.cpp" "hoofball.cpp" "hoof.cpp" 
    "milk_out.cpp" "moocast.cpp" "moo.cpp" "moo_route.cpp" "wormhole.cpp" 
    "bliboard.cpp" "blist.cpp" "diamond.cpp" "fence.cpp" "fence_piano.cpp" 
    "grass.cpp" "grass_plant.cpp" "hay.cpp" "herdining.cpp" "load_bal.cpp" 
    "lomonade.cpp" "madeup.cpp" "paint.cpp" "pairup.cpp" "planting.in" 
    "planting.out" "race.cpp" "rest.cpp" "rut.cpp" "shuffle.cpp" 
    "sleep_her.cpp" "split.cpp" "Traffic.cpp" "cross.cpp" "guess.cpp" "sleep.cpp"
)

for file in "${usaco_files[@]}"; do
    if [ -f "$file" ]; then mv "$file" USACO/; fi
done

echo "Moving Codeforces files..."
cf_files=(
    "anton.cpp" "anya.cpp" "bash_big_day.cpp" "bear.cpp" "ciel.cpp" 
    "drazil.cpp" "kefa.cpp" "kefa_park.cpp" "pasha.cpp" "vas.cpp" 
    "turtle_math.cpp" "two_bottons.cpp" "sort_the_array.cpp" "magic_ship.cpp" 
    "pair_of_topics.cpp" "iva_pav.cpp" "helmet_in_night.cpp" "karen.cpp" 
    "win_or_freeze.cpp" "chat.cpp" "taxi.cpp" "cheap.cpp" "fox.cpp" 
    "johnny.cpp" "first_cf_graph.cpp" "rumor.cpp" "party_monster.cpp" 
    "zero_array.cpp" "drazil.cpp" "c.cpp"
)

for file in "${cf_files[@]}"; do
    if [ -f "$file" ]; then mv "$file" Codeforces/Practice/; fi
done

echo "Moving CSES files..."
cses_files=(
    "cses_stick.cpp" "playlist.cpp" "sub_sum.cpp" "dice.cpp" 
    "flight.cpp" "monster.cpp" "Monster.cpp" "stick.cpp" 
    "sub_sum_constraint.cpp" "array_game.cpp" "lab.cpp"
)

for file in "${cses_files[@]}"; do
    if [ -f "$file" ]; then mv "$file" CSES/; fi
done

echo "Handling contest folders..."
# Move specific contest directories to Codeforces
if [ -d "contest/1899" ]; then mv contest/1899 Codeforces/Contests/; fi
if [ -d "contest/2167" ]; then mv contest/2167 Codeforces/Contests/; fi

# Move any remaining files in the 'contest' folder to Unsorted, then remove the empty folder
if [ -d "contest" ]; then
    mv contest/* Unsorted/ 2>/dev/null
    rmdir contest 2>/dev/null
fi

echo "Sweeping remaining files into Unsorted..."
# Move all remaining loose .cpp, .in, and .out files into Unsorted for manual review
mv *.cpp Unsorted/ 2>/dev/null
mv *.in Unsorted/ 2>/dev/null
mv *.out Unsorted/ 2>/dev/null

echo "Organization complete! Check the Unsorted folder for generic files like test.cpp."
