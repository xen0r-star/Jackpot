import { useEffect, useRef } from 'react';
import Confetti from 'react-confetti';
import { HelpPopup, SlotMachine, ScoreDisplay, ScoreNotifications } from './components';
import type { ScoreNotificationsRef } from './components/ScoreNotifications';
import type { ReelState } from './types';
import { useGameState, useWindowDimensions } from './hooks';
import { SYMBOLS, GAME_CONFIG } from './constants';
import { calculateWinPoints } from './utils';


function App() {
    const gameState = useGameState();
    const windowDimensions = useWindowDimensions();
    const scoreNotificationsRef = useRef<ScoreNotificationsRef>(null);

    const {
        reels,
        isSpinning,
        score,
        bestScore,
        spinsRemaining,
        showConfetti,
        showHelpPopup,
        showJackpot,
        setReels,
        setIsSpinning,
        setScore,
        setBestScore,
        setSpinsRemaining,
        setShowConfetti,
        setShowHelpPopup,
        setShowJackpot,
        resetGame
    } = gameState;


    const startSpin = () => {
        if (isSpinning || spinsRemaining <= 0) return;

        setIsSpinning(true);
        setSpinsRemaining(prev => prev - 1);

        setReels(prevReels =>
            prevReels.map((reel, index) => ({
                ...reel,
                isSpinning: true,
                stopDelay: GAME_CONFIG.SPIN_ANIMATION_DURATION + (index * GAME_CONFIG.SPIN_STAGGER_DELAY)
            }))
        );

        const finalReels: ReelState[] = [];

        reels.forEach((_, index) => {
            setTimeout(() => {
                const newSymbol = Math.floor(Math.random() * SYMBOLS.length);
                
                setReels(prevReels => {
                    const newReels = [...prevReels];
                    newReels[index] = {
                        ...newReels[index],
                        isSpinning: false,
                        currentSymbol: newSymbol
                    };
                    finalReels[index] = newReels[index];
                    return newReels;
                });

                if (index === 2) {
                    setTimeout(() => {
                        setIsSpinning(false);
                        // Utiliser les finalReels au lieu de l'ancien état
                        checkWinWithReels(finalReels);
                    }, 100);
                }
            }, GAME_CONFIG.SPIN_ANIMATION_DURATION + (index * GAME_CONFIG.SPIN_STAGGER_DELAY));
        });
    };




    const checkWinWithReels = (currentReels: ReelState[]) => {
        const symbols = currentReels.map(reel => SYMBOLS[reel.currentSymbol]);
        const result = calculateWinPoints(symbols);

        setScore(prevScore => {
            const newScore = prevScore + result.points;
            if (newScore > bestScore) {
                setBestScore(newScore);
            }
            return newScore;
        });

        if (result.points > 0) {
            scoreNotificationsRef.current?.addNotification(result.points);
        }

        if (result.extraSpins > 0) {
            setSpinsRemaining(prev => prev + result.extraSpins);
        }

        // Vérifier si c'est un triple 7 pour l'animation jackpot
        const isJackpot = symbols[0] === '7' && symbols[1] === '7' && symbols[2] === '7';
        
        if (isJackpot) {
            setShowJackpot(true);
            setShowConfetti(true);
            
            // Animation jackpot dure plus longtemps
            setTimeout(() => {
                setShowJackpot(false);
                setShowConfetti(false);
            }, 10000); // 10 secondes pour le jackpot
        } else if (result.points > 0 || result.extraSpins > 0) {
            setShowConfetti(true);

            // Laisser le temps aux confettis de finir de tomber (6 secondes)
            setTimeout(() => {
                setShowConfetti(false);
            }, 6000);
        }
    };




    useEffect(() => {
        const intervals: NodeJS.Timeout[] = [];

        reels.forEach((reel, index) => {
            if (reel.isSpinning) {
                const interval = setInterval(() => {
                    setReels(prevReels => {
                        const newReels = [...prevReels];
                        newReels[index] = {
                            ...newReels[index],
                            currentSymbol: (newReels[index].currentSymbol + 1) % SYMBOLS.length
                        };
                        return newReels;
                    });
                }, GAME_CONFIG.REEL_ANIMATION_SPEED);
                intervals.push(interval);
            }
        });

        return () => {
            intervals.forEach(interval => clearInterval(interval));
        };
    }, [reels, setReels]);




    return (
        <div className="min-h-screen flex flex-col items-center justify-center p-8">
            {/* Jackpot Animation Overlay */}
            {showJackpot && (
                <div className="fixed inset-0 z-50 flex items-center justify-center bg-black bg-opacity-50 pointer-events-none">
                    <div className="text-center">
                        <h1 className="text-9xl font-bold text-yellow-400 jackpot-animation mb-8">
                            🎰 JACKPOT! 🎰
                        </h1>
                        <div className="text-6xl font-bold text-white jackpot-animation">
                            +2500 POINTS!
                        </div>
                        <div className="text-4xl text-yellow-300 mt-4 animate-bounce">
                            ⭐ TRIPLE SEVEN ⭐
                        </div>
                    </div>
                </div>
            )}

            {/* Confetti */}
            {showConfetti && (
                <>
                    <Confetti
                        width={windowDimensions.width}
                        height={windowDimensions.height}
                        recycle={false}
                        numberOfPieces={showJackpot ? GAME_CONFIG.CONFETTI_PIECES * 2 : GAME_CONFIG.CONFETTI_PIECES}
                        gravity={0.4}
                        initialVelocityX={15}
                        initialVelocityY={-10}
                        confettiSource={{
                            x: 0,
                            y: windowDimensions.height / 2,
                            w: 10,
                            h: 10
                        }}
                        colors={showJackpot ? ['#FFD700', '#FFD700', '#FFD700', '#FF6B6B', '#4ECDC4'] : ['#FFD700', '#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4', '#FFEAA7']}
                    />
                    <Confetti
                        width={windowDimensions.width}
                        height={windowDimensions.height}
                        recycle={false}
                        numberOfPieces={showJackpot ? GAME_CONFIG.CONFETTI_PIECES * 2 : GAME_CONFIG.CONFETTI_PIECES}
                        gravity={0.4}
                        initialVelocityX={-15}
                        initialVelocityY={-10}
                        confettiSource={{
                            x: windowDimensions.width - 10,
                            y: windowDimensions.height / 2,
                            w: 10,
                            h: 10
                        }}
                        colors={showJackpot ? ['#FFD700', '#FFD700', '#FFD700', '#FF6B6B', '#4ECDC4'] : ['#FFD700', '#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4', '#FFEAA7']}
                    />
                    {showJackpot && (
                        <>
                            <Confetti
                                width={windowDimensions.width}
                                height={windowDimensions.height}
                                recycle={false}
                                numberOfPieces={GAME_CONFIG.CONFETTI_PIECES}
                                gravity={0.3}
                                initialVelocityX={0}
                                initialVelocityY={-20}
                                confettiSource={{
                                    x: windowDimensions.width / 2,
                                    y: 0,
                                    w: windowDimensions.width,
                                    h: 10
                                }}
                                colors={['#FFD700', '#FFD700', '#FFD700', '#FFFF00']}
                            />
                        </>
                    )}
                </>
            )}

            {/* Score Notification */}
            <ScoreNotifications ref={scoreNotificationsRef} />

            {/* Help Popup */}
            <HelpPopup 
                isOpen={showHelpPopup} 
                onClose={() => setShowHelpPopup(false)} 
            />
            
            <div className="bg-[#0B1123] rounded-3xl p-8 shadow-[12px_12px_0px_0px_#080d1b]">
                <h1 className={`px-6 py-1.5 text-6xl border-[14px] font-bold text-center mb-8 rounded-xl bg-[#b62345c7] text-[#ffffffe6] drop-shadow-lg ${showJackpot ? 'jackpot-glow jackpot-animation' : 'border-[#B62345]'}`}>
                    JACKPOT
                </h1>

                {/* Slot machine */}
                <SlotMachine reels={reels} />
                
                {/* Score Display et Controls */}
                <ScoreDisplay
                    score={score}
                    bestScore={bestScore}
                    spinsRemaining={spinsRemaining}
                    onSpin={startSpin}
                    onShowHelp={() => setShowHelpPopup(true)}
                    onReset={resetGame}
                    isSpinning={isSpinning}
                />

            </div>
        </div>
    );
}

export default App;