import React from 'react';


interface ScoreDisplayProps {
    score: number;
    bestScore: number;
    spinsRemaining: number;
    onSpin: () => void;
    onShowHelp: () => void;
    onReset: () => void;
    isSpinning: boolean;
}

const ScoreDisplay: React.FC<ScoreDisplayProps> = ({
    score,
    bestScore,
    spinsRemaining,
    onSpin,
    onShowHelp,
    onReset,
    isSpinning
}) => {
    return (
        <div className='flex flex-row justify-between items-stretch mt-6 min-h-[120px]'>
            <div className='flex flex-col items-center justify-top h-auto flex-1 gap-2.5'>
                {/* Help button */}
                <button 
                    onClick={onShowHelp}
                    className='bg-[#b62345c7] hover:bg-[#96213cc7] p-1 w-12 h-12 cursor-pointer aspect-square text-3xl font-bold rounded-full shadow-lg transform transition-all duration-200 flex items-center justify-center border-[#B62345] border-[6px] text-white hover:scale-105 active:scale-95'
                >
                    <svg className='h-full w-full' width="64" height="64" viewBox="0 0 64 64" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <path d="M20 20.5C20 20.5 20.18 16.375 24.1925 13.0675C26.575 11.1038 29.4362 10.535 32 10.5C34.3412 10.4713 36.4338 10.8675 37.685 11.4775C39.8238 12.525 44 15.075 44 20.5C44 26.2088 40.3525 28.7963 36.2062 31.6475C32.06 34.4988 31 37.295 31 40.5" stroke="white" strokeWidth="5" strokeMiterlimit="10" strokeLinecap="round"/>
                        <path d="M31 53.9985C33.2091 53.9985 35 52.2077 35 49.9985C35 47.7894 33.2091 45.9985 31 45.9985C28.7909 45.9985 27 47.7894 27 49.9985C27 52.2077 28.7909 53.9985 31 53.9985Z" fill="white"/>
                    </svg>
                </button>

                {/* Reset button */}
                <button 
                    onClick={onReset}
                    className='bg-[#b62345c7] hover:bg-[#96213cc7] p-1 w-12 h-12 cursor-pointer aspect-square text-3xl font-bold rounded-full shadow-lg transform transition-all duration-200 flex items-center justify-center border-[#B62345] border-[6px] text-white hover:scale-105 active:scale-95'
                >
                    <svg className='h-full w-full' width="64" height="64" viewBox="0 0 64 64" fill="none" xmlns="http://www.w3.org/2000/svg">
                        <path d="M50 18.5L47.36 15.4288C45.1216 13.0777 42.4282 11.2067 39.4438 9.9296C36.4593 8.65249 33.2462 7.99598 30 8.00002C16.75 8.00002 6 18.75 6 32C6 45.25 16.75 56 30 56C34.9638 55.9997 39.8054 54.461 43.8587 51.5957C47.912 48.7304 50.9776 44.6793 52.6338 40" stroke="white" strokeWidth="5" strokeMiterlimit="10" strokeLinecap="round"/>
                        <path d="M58.0001 12.1773V25.9998C58.0001 26.5302 57.7894 27.0389 57.4143 27.414C57.0393 27.7891 56.5306 27.9998 56.0001 27.9998H42.1776C40.3951 27.9998 39.5026 25.846 40.7626 24.586L54.5864 10.7623C55.8464 9.49978 58.0001 10.3948 58.0001 12.1773Z" fill="white"/>
                    </svg>
                </button>
            </div>

            <div className='w-full flex flex-col justify-between items-end flex-3'>
                {/* Score */}
                <div className='bg-[#b62345c7] text-[#ffffffe6] font-bold w-full rounded-xl text-right px-1.5 border-[#B62345] border-[8px] mb-2'>
                    {score}
                </div>

                {/* Best score */}
                <div className='bg-[#ffcd1ec7] text-[#ffffffe6] font-bold w-full rounded-xl text-right px-1.5 border-[#FFCD1E] border-[8px] mb-2'>
                    {bestScore}
                </div>

                {/* Number SPIN */}
                <div className='bg-[#ffcd1ec7] text-[#ffffffe6] font-bold w-20 rounded-xl text-right px-1.5 border-[#FFCD1E] border-[6px]'>
                    {spinsRemaining}
                </div>
            </div>

            <div className='flex flex-col items-center justify-center h-auto flex-2'>
                {/* Spin button */}
                <button
                    onClick={onSpin}
                    disabled={isSpinning || spinsRemaining <= 0}
                    className={`
                        h-full aspect-square text-3xl font-bold rounded-full shadow-lg transform transition-all duration-200
                        flex items-center justify-center border-[10px] text-white
                        ${!isSpinning && spinsRemaining > 0
                            ? 'border-[#FFCD1E] bg-[#FFCD1Ec7] hover:scale-105 active:scale-95 cursor-pointer'
                            : 'border-[#B62345] bg-[#b62345c7] cursor-not-allowed'
                        }
                    `}
                >
                    SPIN
                </button>
            </div>
        </div>
    );
};

export default ScoreDisplay;