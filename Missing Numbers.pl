# Enter your code here. Read input from STDIN. Print output to STDOUT
$line = <>;
$line = <>;
chomp $line;
@A = split /[\s]+/,$line;
my %a;
foreach $ele (@A){
	if(not exists $a{$ele}){
		$a{$ele} = 1;
	}else{
		$a{$ele} = $a{$ele} + 1;
	}
}
$line = <>;
$line = <>;
chomp $line;
@B = split /[\s]+/,$line;
my %b;
foreach $ele (@B){
	if(not exists $b{$ele}){
		$b{$ele} = 1;
	}else{
		$b{$ele} = $b{$ele} + 1;
	}
}

foreach $ele (sort(keys(%b))){
	if(not exists $a{$ele}){
		print $ele." ";
	}elsif($a{$ele} != $b{$ele}){
		print $ele." ";
	}
}