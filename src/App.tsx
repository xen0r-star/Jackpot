import { useState, useEffect } from 'react';
import Confetti from 'react-confetti';
import Prix from './assets/images/Prix.svg';


const SYMBOLS = [
    '7',
    'Banane',
    'Bar',
    'Cerise',
    'Citron',
    'Coeur',
    'Diament',
    'Dollar',
    'Orange',
    'Pasteque',
    'Pomme',
    'Prune',
    'Trefle'
];


interface ReelState {
    currentSymbol: number;
    isSpinning: boolean;
    stopDelay: number;
}

function App() {
    const [reels, setReels] = useState<ReelState[]>([
        { currentSymbol: 0, isSpinning: false, stopDelay: 0 },
        { currentSymbol: 1, isSpinning: false, stopDelay: 0 },
        { currentSymbol: 2, isSpinning: false, stopDelay: 0 }
    ]);

    const [isSpinning, setIsSpinning] = useState(false);
    const [score, setScore] = useState(0);
    const [bestScore, setBestScore] = useState(0);
    const [spinsRemaining, setSpinsRemaining] = useState(100);
    const [showConfetti, setShowConfetti] = useState(false);
    const [windowDimensions, setWindowDimensions] = useState({
        width: window.innerWidth,
        height: window.innerHeight
    });

    const startSpin = () => {
        if (isSpinning || spinsRemaining <= 0) return;

        setIsSpinning(true);
        setSpinsRemaining(prev => prev - 1);

        setReels(prevReels =>
            prevReels.map((reel, index) => ({
                ...reel,
                isSpinning: true,
                stopDelay: 2000 + (index * 500)
            }))
        );


        reels.forEach((_, index) => {
            setTimeout(() => {
                setReels(prevReels => {
                    const newReels = [...prevReels];
                    newReels[index] = {
                        ...newReels[index],
                        isSpinning: false,
                        currentSymbol: Math.floor(Math.random() * SYMBOLS.length)
                    };
                    return newReels;
                });

                if (index === 2) {
                    setTimeout(() => {
                        setIsSpinning(false);
                        checkWin();
                    }, 100);
                }
            }, 2000 + (index * 500));
        });
    };


    const checkWin = () => {
        setTimeout(() => {
            setReels(currentReels => {
                const symbols = currentReels.map(reel => SYMBOLS[reel.currentSymbol]);
                let points = 0;
                let extraSpins = 0;

                // Vérifier les combinaisons spécifiques
                if (symbols[0] === '7' && symbols[1] === '7' && symbols[2] === '7') {
                    // Triple 7 = +2500 points
                    points = 2500;
                } else if (
                    (symbols.includes('7') && symbols.includes('Dollar') && symbols.includes('Bar')) ||
                    (symbols[0] === symbols[1] && symbols[1] === symbols[2] && ['7', 'Dollar', 'Bar'].includes(symbols[0]))
                ) {
                    // (7, Dollar, Bar) = +1000 points
                    points = 1000;
                } else if (
                    (symbols.includes('Pomme') && symbols.includes('Cerise') && symbols.includes('Pasteque')) ||
                    (symbols[0] === symbols[1] && symbols[1] === symbols[2] && ['Pomme', 'Cerise', 'Pasteque'].includes(symbols[0]))
                ) {
                    // (Pomme, Cerise, Pastèque) = +500 points
                    points = 500;
                } else if (
                    (symbols.includes('Citron') && symbols.includes('Orange') && symbols.includes('Banane')) ||
                    (symbols[0] === symbols[1] && symbols[1] === symbols[2] && ['Citron', 'Orange', 'Banane'].includes(symbols[0]))
                ) {
                    // (Citron, Orange, Banane) = +100 points
                    points = 100;
                } else if (symbols.filter(s => s === 'Diament').length >= 1) {
                    // Diamant = +50 points par diamant
                    points = symbols.filter(s => s === 'Diament').length * 50;
                }

                // Vérifier les trèfles pour les spins bonus
                const trefleCount = symbols.filter(s => s === 'Trefle').length;
                if (trefleCount > 0) {
                    extraSpins = trefleCount;
                }

                // Mettre à jour les scores
                setScore(prevScore => {
                    const newScore = prevScore + points;
                    if (newScore > bestScore) {
                        setBestScore(newScore);
                    }
                    return newScore;
                });

                // Ajouter les spins bonus
                if (extraSpins > 0) {
                    setSpinsRemaining(prev => prev + extraSpins);
                }

                // Déclencher les confettis si gain
                if (points > 0 || extraSpins > 0) {
                    setShowConfetti(true);
                    // Arrêter les confettis après 3 secondes
                    setTimeout(() => {
                        setShowConfetti(false);
                    }, 3000);
                }

                return currentReels;
            });
        }, 200);
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
                }, 200);
                intervals.push(interval);
            }
        });

        return () => {
            intervals.forEach(interval => clearInterval(interval));
        };
    }, [reels]);

    // Gérer le redimensionnement de la fenêtre pour les confettis
    useEffect(() => {
        const handleResize = () => {
            setWindowDimensions({
                width: window.innerWidth,
                height: window.innerHeight
            });
        };

        window.addEventListener('resize', handleResize);
        return () => window.removeEventListener('resize', handleResize);
    }, []);

    return (
        <div className="min-h-screen flex flex-col items-center justify-center p-8">
            {/* Confettis lors des gains - Canon gauche */}
            {showConfetti && (
                <>
                    <Confetti
                        width={windowDimensions.width}
                        height={windowDimensions.height}
                        recycle={false}
                        numberOfPieces={150}
                        gravity={0.4}
                        initialVelocityX={15}
                        initialVelocityY={-10}
                        confettiSource={{
                            x: 0,
                            y: windowDimensions.height / 2,
                            w: 10,
                            h: 10
                        }}
                        colors={['#FFD700', '#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4', '#FFEAA7']}
                    />
                    {/* Canon droit */}
                    <Confetti
                        width={windowDimensions.width}
                        height={windowDimensions.height}
                        recycle={false}
                        numberOfPieces={150}
                        gravity={0.4}
                        initialVelocityX={-15}
                        initialVelocityY={-10}
                        confettiSource={{
                            x: windowDimensions.width - 10,
                            y: windowDimensions.height / 2,
                            w: 10,
                            h: 10
                        }}
                        colors={['#FFD700', '#FF6B6B', '#4ECDC4', '#45B7D1', '#96CEB4', '#FFEAA7']}
                    />
                </>
            )}
            
            <div className="bg-[#0B1123] rounded-3xl p-8 shadow-[12px_12px_0px_0px_#080d1b]">
                <h1 className="px-6 py-1.5 text-6xl border-[#B62345] border-[14px] font-bold text-center mb-8 rounded-xl bg-[#EDEDED] text-[#05070E] drop-shadow-lg">
                    JACKPOT
                </h1>

                {/* Slot machine */}
                <div className="flex flex-col items-center">
                    <div className="w-md h-40 px-8 bg-white border-[#FFCD1E] border-[14px] rounded-xl shadow-lg overflow-hidden relative flex">
                        {reels.map((reel, index) => (
                            <div key={index} className="flex-1 relative">
                                {/* Fenêtre de visualisation */}
                                <div className="absolute inset-0 flex items-center justify-center z-10">
                                    <div className="w-20 h-20 flex items-center justify-center">
                                        {!reel.isSpinning && (
                                            <img
                                                src={`/src/assets/images/symbole/${SYMBOLS[reel.currentSymbol]}.svg`}
                                                alt={SYMBOLS[reel.currentSymbol]}
                                                className="w-full h-full"
                                            />
                                        )}
                                    </div>
                                </div>

                                {/* Animation de défilement vertical */}
                                {reel.isSpinning && (
                                    <div className="absolute inset-0 overflow-hidden">
                                        <div className="reel-scroll flex flex-col">
                                            {[...Array(20)].map((_, i) => (
                                                <div key={i} className="w-32 h-32 flex items-center justify-center flex-shrink-0">
                                                    <img
                                                        src={`/src/assets/images/symbole/${SYMBOLS[(reel.currentSymbol + i) % SYMBOLS.length]}.svg`}
                                                        alt={SYMBOLS[(reel.currentSymbol + i) % SYMBOLS.length]}
                                                        className="w-20 h-20"
                                                    />
                                                </div>
                                            ))}
                                        </div>
                                    </div>
                                )}
                            </div>
                        ))}

                        {/* Left and right triangle */}
                        <svg className='absolute right-0 top-1/2 -translate-y-1/2 translate-x-1.5' width="27" height="31" viewBox="0 0 27 31" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M2.47589 12.1014C-0.044969 13.666 -0.0449668 17.334 2.47589 18.8986L20.8906 30.3278C23.5553 31.9816 27 30.0653 27 26.9291V4.07085C27 0.93473 23.5553 -0.981563 20.8906 0.672236L2.47589 12.1014Z" fill="#FFCD1E"/>
                        </svg>
                        <svg className='absolute left-0 top-1/2 -translate-y-1/2 -translate-x-1.5' width="27" height="31" viewBox="0 0 27 31" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M24.5241 12.1014C27.045 13.666 27.045 17.334 24.5241 18.8986L6.10936 30.3278C3.44474 31.9816 0 30.0653 0 26.9291V4.07085C0 0.93473 3.44474 -0.981563 6.10936 0.672236L24.5241 12.1014Z" fill="#FFCD1E"/>
                        </svg>



                        {/* Effet de masque pour créer l'illusion de défilement */}
                        <div className="absolute top-0 left-0 right-0 h-4 bg-gradient-to-b from-white to-transparent z-20"></div>
                        <div className="absolute bottom-0 left-0 right-0 h-4 bg-gradient-to-t from-white to-transparent z-20"></div>
                    </div>
                </div>
                
                <div className='flex flex-row justify-between mt-6'>
                    <img src={Prix} alt="Prix"/>

                    <div>
                        {/* Score */}
                        <div className='text-[#05070e] font-bold bg-[#EDEDED] w-36 rounded-xl text-right px-1.5 border-[#B62345] border-[8px] mb-2'>
                            {score}
                        </div>
                        {/* Best score */}
                        <div className='text-[#05070e] font-bold bg-[#EDEDED] w-36 rounded-xl text-right px-1.5 border-[#FFCD1E] border-[8px]'>
                            {bestScore}
                        </div>
                    </div>

                    <div className='flex flex-col items-center justify-between gap-3.5'>
                        {/* Spin button */}
                        <div className="text-center">
                            <button
                                onClick={startSpin}
                                disabled={isSpinning || spinsRemaining <= 0}
                                className={`
                                    w-24 h-24 text-2xl font-bold rounded-full shadow-lg transform transition-all duration-200
                                    flex items-center justify-center border-[#B62345] border-[10px] text-white
                                    ${!isSpinning && spinsRemaining > 0
                                        ? 'bg-[#FFCD1E] hover:scale-105 active:scale-95 cursor-pointer'
                                        : 'bg-[#9A0024] cursor-not-allowed'
                                    }
                                `}
                            >
                                SPIN
                            </button>
                        </div>

                        {/* Number SPIN */}
                        <div className='text-[#05070e] font-bold bg-[#EDEDED] w-16 rounded-xl text-center px-1.5 border-[#FFCD1E] border-[6px]'>
                            {spinsRemaining}
                        </div>
                    </div>
                </div>

                {/* Result message */}
                {/* {message && (
                    <div className="text-center">
                        <div className="bg-white rounded-xl p-4 shadow-lg">
                            <p className="text-2xl font-bold text-gray-800">{message}</p>
                        </div>
                    </div>
                )} */}
            </div>
        </div>
    );
}

export default App;
