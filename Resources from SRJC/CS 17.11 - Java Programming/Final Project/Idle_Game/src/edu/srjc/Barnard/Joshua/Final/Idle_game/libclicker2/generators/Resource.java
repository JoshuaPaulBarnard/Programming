package edu.srjc.Barnard.Joshua.Final.Idle_game.libclicker2.generators;

import java.math.BigInteger;

/**
 * Represents a resource that can be generated
 * by the generators.
 */
public interface Resource
{
    void generate( BigInteger amount );
}
