#ifndef CHEMICALMEASUREMENT_H
#define CHEMICALMEASUREMENT_H


class chemicalMeasurement
{
    public:
        chemicalMeasurement();
        virtual ~chemicalMeasurement();

        void setPH(float ph);
        float getPH();
        void setNitrite(float nitrite);
        float getNitrite();
        void setNitrate(float nitrate);
        float getNitrate();
        void setWaterHardness(float waterHardness);
        float getWaterHardness();

    private:
        float _pH;
        float _nitrite;
        float _nitrate;
        float _waterHardness;

};

#endif // CHEMICALMEASUREMENT_H
