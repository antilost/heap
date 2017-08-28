#!/usr/bin/perl

=pod

    Test Class::Accessor - Automated accessor generation

    http://search.cpan.org/~kasei/Class-Accessor-0.34/lib/Class/Accessor.pm

=cut

use strict;
use warnings;
use 5.014;

use Data::Dumper;

use Student;

my $s = Student->new("John", "iu7-11");

# call our accessors (values defined while creating new Student object)
say "Name: " . $s->name() . ", group: " . $s->group();

# mark will be undefined, although such an accessor exists
say "M: " . ($s->mark() // "UNDEF");

# accessor age() has not implemented, so we are expecting error here
eval {
    say "Age: " . $s->age();
};
if ($@) {
    say "age() failed: $@";
}

exit(0);
