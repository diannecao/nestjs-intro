import * as mongoose from 'mongoose';
export const ProductSchema = new mongoose.Schema({
    title: {type: String, required: true},
    description: {type: String, required: true},
    price: {type: String, required: true},

});


export class Product{
    

    constructor(public id: string, public title: string, public  description :string, public price: number) {
        
    };
}