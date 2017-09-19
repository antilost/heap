#!/usr/bin/perl
use strict;
use warnings;
use 5.014;

=head
tip
    Redefine (mock) standart global functions with own one.

    https://stackoverflow.com/questions/44807612/how-to-mock-built-in-operators

=cut

say "before: " . localtime( time() );

BEGIN {
    *CORE::GLOBAL::localtime = sub {
        return "ggg";
    };
}

say "after: " . localtime( time() );