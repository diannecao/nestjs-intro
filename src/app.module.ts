import { Module } from '@nestjs/common';
import { MongooseModule } from '@nestjs/mongoose';

import { AppController } from './app.controller';
import { AppService } from './app.service';
import { ProductsModule } from './Products/product.module';

@Module({
  imports: [ProductsModule, MongooseModule.forRoot('mongodb+srv://diannecao:diannecao@cluster0.jdpfyfn.mongodb.net/')],
  controllers: [AppController],
  providers: [AppService],
})
export class AppModule {}
