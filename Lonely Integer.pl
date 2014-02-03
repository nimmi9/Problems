#!/usr/bin/perl
# Head ends here
sub lonelyinteger{
   $array_ref = shift;
   @A = @{$array_ref};
    $ans = $A[0];
    for($i=1; $i < (scalar @A); $i++){
        $ans = $ans ^ $A[$i];
    }
    return $ans;
}
# Tail starts here
$_a_size = <>;
$_b = <>;
@_b_split = split(' ',$_b);

$res = lonelyinteger(\@_b_split);
print "$res\n";