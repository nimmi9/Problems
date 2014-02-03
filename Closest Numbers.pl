# Enter your code here. Read input from STDIN. Print output to STDOUT
$line = <>;
$line = <>;
chomp $line;
@A = sort {$a <=> $b} split (/[\s]+/,$line);
$min = 20000001; 
for($i=1;$i<(scalar @A);$i++){
	$diff = $A[$i] - $A[($i-1)];
	if($diff<0){
		$diff = -1 * $diff;
	}
	if($min > $diff){
		$min = $diff;
	}
}
for($i=1;$i<(scalar @A);$i++){
	$diff = $A[$i] - $A[($i-1)];
	if($diff<0){
		$diff = -1 * $diff;
	}
	if($min == $diff){
		print $A[($i-1)]." ".$A[$i]." ";
	}
}