package Student;

use Class::Accessor "antlers";
has name  => (is => "rw");
has group => (is => "rw");
has mark => (is => "rw");

sub new {
    my ($classname, $name, $group) = @_;
    
    my $self = {};
    $self->{name} = $name;
    $self->{group} = $group;

    return bless($self, $classname);
}

1;
