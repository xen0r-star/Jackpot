import React from 'react';


interface HelpPopupProps {
    isOpen: boolean;
    onClose: () => void;
}

const HelpPopup: React.FC<HelpPopupProps> = ({ isOpen, onClose }) => {
    if (!isOpen) return null;

    return (
        <div className="fixed inset-0 bg-[#000000b1] bg-opacity-50 flex items-center justify-center z-50 p-4">
            <div className="bg-[#0B1123] rounded-[5px] p-8 max-w-2xl max-h-[90vh] overflow-y-auto border-4 border-[#B62345]">
                <div className="flex justify-between items-center mb-6">
                    <h2 className="text-4xl font-bold text-[#FFCD1E]">🎰 GUIDE DU JEU</h2>
                    <button 
                        onClick={onClose}
                        className="cursor-pointer w-10 h-10"
                    >
                        <svg className='w-full h-full' viewBox="0 0 64 64" fill="none" xmlns="http://www.w3.org/2000/svg">
                            <path d="M36.2425 32L48.1175 20.125C48.6811 19.5624 48.9981 18.799 48.9988 18.0027C48.9995 17.2063 48.6838 16.4424 48.1213 15.8788C47.5587 15.3152 46.7952 14.9982 45.9989 14.9975C45.2026 14.9968 44.4386 15.3124 43.875 15.875L32 27.75L20.125 15.875C19.5614 15.3114 18.797 14.9948 18 14.9948C17.203 14.9948 16.4386 15.3114 15.875 15.875C15.3114 16.4386 14.9948 17.203 14.9948 18C14.9948 18.797 15.3114 19.5614 15.875 20.125L27.75 32L15.875 43.875C15.3114 44.4386 14.9948 45.203 14.9948 46C14.9948 46.797 15.3114 47.5614 15.875 48.125C16.4386 48.6886 17.203 49.0052 18 49.0052C18.797 49.0052 19.5614 48.6886 20.125 48.125L32 36.25L43.875 48.125C44.4386 48.6886 45.203 49.0052 46 49.0052C46.797 49.0052 47.5614 48.6886 48.125 48.125C48.6886 47.5614 49.0052 46.797 49.0052 46C49.0052 45.203 48.6886 44.4386 48.125 43.875L36.2425 32Z" fill="white"/>
                        </svg>
                    </button>
                </div>
                
                <div className="text-white space-y-6">
                    <div>
                        <h3 className="text-2xl font-bold text-[#FFCD1E] mb-3">🎯 COMMENT JOUER</h3>
                        <ul className="space-y-2 text-lg">
                            <li>• Cliquez sur <span className="text-[#FFCD1E] font-bold">SPIN</span> pour faire tourner les rouleaux</li>
                            <li>• Vous commencez avec <span className="text-[#FFCD1E] font-bold">100 tours gratuits</span></li>
                            <li>• Alignez les symboles pour gagner des points !</li>
                        </ul>
                    </div>

                    <div>
                        <h3 className="text-2xl font-bold text-[#FFCD1E] mb-3">💰 COMBINAISONS GAGNANTES</h3>
                        <div className="space-y-3 text-lg">
                            <div className="bg-[#1a1a2e] p-3 rounded-lg border-2 border-[#FFCD1E]">
                                <span className="text-[#FFCD1E] font-bold">🎰 7-7-7</span> = <span className="text-green-400 font-bold">+2500 points</span>
                            </div>
                            <div className="bg-[#1a1a2e] p-3 rounded-lg border-2 border-[#B62345]">
                                <span className="text-[#FFCD1E] font-bold">💰 7 + Dollar + Bar</span> = <span className="text-green-400 font-bold">+1000 points</span>
                            </div>
                            <div className="bg-[#1a1a2e] p-3 rounded-lg border-2 border-[#B62345]">
                                <span className="text-[#FFCD1E] font-bold">🍎 Pomme + Cerise + Pastèque</span> = <span className="text-green-400 font-bold">+500 points</span>
                            </div>
                            <div className="bg-[#1a1a2e] p-3 rounded-lg border-2 border-[#B62345]">
                                <span className="text-[#FFCD1E] font-bold">🍋 Citron + Orange + Banane</span> = <span className="text-green-400 font-bold">+100 points</span>
                            </div>
                            <div className="bg-[#1a1a2e] p-3 rounded-lg border-2 border-[#B62345]">
                                <span className="text-[#FFCD1E] font-bold">💎 Par Diamant</span> = <span className="text-green-400 font-bold">+50 points</span>
                            </div>
                        </div>
                    </div>

                    <div>
                        <h3 className="text-2xl font-bold text-[#FFCD1E] mb-3">🍀 BONUS SPÉCIAUX</h3>
                        <div className="bg-[#1a1a2e] p-3 rounded-lg border-2 border-green-500">
                            <span className="text-[#FFCD1E] font-bold">🍀 Trèfle</span> = <span className="text-green-400 font-bold">+1 tour gratuit par trèfle</span>
                        </div>
                    </div>

                    <div>
                        <h3 className="text-2xl font-bold text-[#FFCD1E] mb-3">📊 STATISTIQUES</h3>
                        <ul className="space-y-2 text-lg">
                            <li>• <span className="text-[#B62345] font-bold">Score actuel</span> : Vos points de cette partie</li>
                            <li>• <span className="text-[#FFCD1E] font-bold">Meilleur score</span> : Record personnel</li>
                            <li>• <span className="text-[#FFCD1E] font-bold">Tours restants</span> : Nombre de spins disponibles</li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    );
};

export default HelpPopup;