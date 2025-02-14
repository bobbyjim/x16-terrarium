#
#     Surprisingly, this is not as nice as makeworld.pl
#


#use v5.10;
use strict;
use warnings;

srand();

# Grid size (80x58)
my $cols = 80;
my $rows = 58;
my @map = map { [(0) x $cols] } (1..$rows);

# Parameters for landmass generation
my $num_landmasses = 5;         # Number of initial landmasses
my $landmass_size  = 20;        # Max size of each landmass

# Generate landmasses
for (1..$num_landmasses) {
    my ($x, $y) = (int(rand($cols)), int(rand($rows)));  # Random starting point
    grow_landmass($x, $y, $landmass_size);
}

# Subroutine to grow landmass
sub grow_landmass {
    my ($x, $y, $remaining) = @_;
    return if $remaining <= 0 || $x < 0 || $y < 0 || $x >= $cols || $y >= $rows;

    # Set land (1)
    $map[$y][$x] = 1;

    # Random walk to adjacent cells
    grow_landmass($x+1, $y, $remaining-1)   if rand() > 0.7;
    grow_landmass($x-1, $y, $remaining-1)   if rand() > 0.7;
    grow_landmass($x, $y+1, $remaining-1)   if rand() > 0.7;
    grow_landmass($x, $y-1, $remaining-1)   if rand() > 0.7;    
    # grow_landmass($x+1, $y+1, $remaining-1) if rand() > 0.5;
    # grow_landmass($x-1, $y+1, $remaining-1) if rand() > 0.5;
    # grow_landmass($x+1, $y-1, $remaining-1) if rand() > 0.5;
    # grow_landmass($x-1, $y-1, $remaining-1) if rand() > 0.5;    
}

# Show terrain (basic)
for my $y (0..$rows-1) {
    for my $x (0..$cols-1) {
        print $map[$y][$x] ? 'x' : '.';
    }
    print "\n";
}
