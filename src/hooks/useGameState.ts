import { useState } from 'react';
import type { ReelState } from '../types';
import { GAME_CONFIG } from '../constants';


export const useGameState = () => {
    const [reels, setReels] = useState<ReelState[]>([
        { currentSymbol: 0, isSpinning: false, stopDelay: 0 },
        { currentSymbol: 1, isSpinning: false, stopDelay: 0 },
        { currentSymbol: 2, isSpinning: false, stopDelay: 0 }
    ]);

    const [isSpinning, setIsSpinning] = useState(false);
    const [score, setScore] = useState(0);
    const [bestScore, setBestScore] = useState(0);
    const [spinsRemaining, setSpinsRemaining] = useState(GAME_CONFIG.INITIAL_SPINS);
    const [showConfetti, setShowConfetti] = useState(false);
    const [showHelpPopup, setShowHelpPopup] = useState(false);
    const [showJackpot, setShowJackpot] = useState(false);

    const resetGame = () => {
        setScore(0);
        setSpinsRemaining(GAME_CONFIG.INITIAL_SPINS);
        setIsSpinning(false);
        setShowConfetti(false);
        setShowJackpot(false);
        setReels([
            { currentSymbol: 0, isSpinning: false, stopDelay: 0 },
            { currentSymbol: 1, isSpinning: false, stopDelay: 0 },
            { currentSymbol: 2, isSpinning: false, stopDelay: 0 }
        ]);
    };

    return {
        // State
        reels,
        isSpinning,
        score,
        bestScore,
        spinsRemaining,
        showConfetti,
        showHelpPopup,
        showJackpot,
        
        // Setters
        setReels,
        setIsSpinning,
        setScore,
        setBestScore,
        setSpinsRemaining,
        setShowConfetti,
        setShowHelpPopup,
        setShowJackpot,
        
        // Actions
        resetGame
    };
};